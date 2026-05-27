/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:47:24 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/27 12:11:42 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (lst)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}

void	handle_flag(char *arg, t_bench *bench)
{
	int	flag;

	flag = check_flag(arg);
	if (flag == 5)
		bench->flag = 1;
	else
		bench->strategy = flag;
}

char	**handle_str(char *arg, t_bench *bench)
{
	char	**args;

	args =	ft_split(arg, ' ');
	if (!args)
		error_and_exit(NULL, NULL, bench);
	return (args);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	**ft_argv_split(int	argc, char **argv, t_bench *bench)
{
	int		i;
	int		count;
	char	**args;

	i = 1;
	count = 0;
	args = NULL;
	(void) argc;
	while (argv[i])
	{
		if (check_flag(argv[i]))
			handle_flag(argv[i], bench);
		else if (ft_strchr(argv[i], ' '))
			args = handle_str(argv[i], bench);
		else
			count++;
		i++;
	}
	if (count > 0 && args)
	{
		free_args(args);
		error_and_exit(NULL, NULL, bench);
	}
	if (args)
		return (args);
	return (argv);
}

void	error_and_exit(t_list **sa, t_list **sb, t_bench *bench)
{
	if (sa && *sa)
		ft_lstclear(sa);
	if (sb && *sb)
		ft_lstclear(sb);
	free(bench);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_flag_check(char** args, char **argv, t_bench *bench)
{
	int	i;

	i = 0;
	if (args != argv)
		i = -1;
	while (args[++i])
	{
		if (check_flag(args[i]))
			continue ;
		else
		{
			if (!is_valid_num(args[i]) || !is_int(args[i]))
			{
				if (args != argv)
					free_args(args);
				error_and_exit(NULL, NULL, bench);
			}
		}
	}
	if (!has_not_repeated(args))
	{
		if (args != argv)
			free_args(args);
		error_and_exit(NULL, NULL, bench);
	}
}

t_list	*parsing(char **args, char **argv)
{
	int		i;
	t_list	*sa;
	int		content;

	i = 1;
	if (args != argv)
		i = 0;
	sa = NULL;
	while (args[i])
	{
		if (!check_flag(args[i]))
		{
			content = (int) ft_atoi(args[i]);
			ft_lstadd_back(&sa, ft_lstnew(content));
		}
		i++;
	}
	if (args != argv)
			free_args(args);
	if (!sa)
		exit(0);
	return (sa);
}
