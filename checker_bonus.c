/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:45:55 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/29 15:53:49 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

char	**handle_str(char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		error_and_exit(NULL, NULL);
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

char	**ft_argv_split(char **argv)
{
	int		i;
	int		count;
	char	**args;

	i = 1;
	count = 0;
	args = NULL;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			args = handle_str(argv[i]);
		else
			count++;
		i++;
	}
	if (count > 0 && args)
	{
		free_args(args);
		error_and_exit(NULL, NULL);
	}
	if (args)
		return (args);
	return (argv);
}

int main(int argc, char **argv)
{
	t_list	*sa;
	t_list	**sb;
	char	**args;

	(void) argc;
	args = ft_argv_split(argv);
	error_flag_check(args, argv);
	sa = parsing(args, argv);
}
