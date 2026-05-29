/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:54:19 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/29 16:15:10 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_flag_check(char **args, char **argv)
{
	int	i;

	i = 0;
	if (args != argv)
		i = -1;
	while (args[++i])
	{
		if (!is_valid_num(args[i]) || !is_int(args[i]))
		{
			if (args != argv)
				free_args(args);
			error_and_exit(NULL, NULL);
		}
	}
	if (!has_not_repeated(args))
	{
		if (args != argv)
			free_args(args);
		error_and_exit(NULL, NULL);
	}
}

void	error_and_exit(t_list **sa, t_list **sb)
{
	if (sa && *sa)
		ft_lstclear(sa);
	if (sb && *sb)
		ft_lstclear(sb);
	write(2, "Error\n", 6);
	exit(1);
}

char	*remove_zeros(char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] == '0')
		i++;
	if (!arg[i])
	{
		arg[j] = '0';
		return (arg);
	}
	if (arg[j] == '-')
		j++;
	while (arg[i])
		arg[j++] = arg[i++];
	arg[j] = '\0';
	return (arg);
}

int	is_valid_num(char *arg)
{
	int	i;

	i = 0;
	arg = remove_zeros(arg);
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i] >= '0' && arg[i] <= '9' && i < 11)
		i++;
	if (arg[i])
		return (0);
	if (!arg[i] && (arg[i - 1] == '+' || arg[i - 1] == '-'))
		return (0);
	return (1);
}

int	is_int(char *arg)
{
	long	num;

	num = ft_atoi(arg);
	if (num < (long) INT_MIN || num > (long) INT_MAX)
		return (0);
	return (1);
}

int	has_not_repeated(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(remove_zeros(argv[i]), remove_zeros(argv[j])) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi(const char *nptr)
{
	long	i;
	long	signal;

	i = 0;
	signal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signal *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i = i * 10 + *nptr - 48;
		nptr++;
	}
	return (i * signal);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while ((s1[n] == s2[n]) && (s1[n] != '\0'))
	{
		n++;
	}
	return (s1[n] - s2[n]);
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
		content = (int) ft_atoi(args[i]);
		ft_lstadd_back(&sa, ft_lstnew(content));
		i++;
	}
	if (args != argv)
		free_args(args);
	if (!sa)
		exit(0);
	return (sa);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
