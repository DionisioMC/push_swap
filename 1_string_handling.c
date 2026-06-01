/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_string_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:15:18 by hede-car          #+#    #+#             */
/*   Updated: 2026/06/01 10:19:07 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_argv_split(char **argv, t_bench *bench)
{
	int		i;
	int		count;
	char	**args;

	i = 1;
	count = 0;
	args = NULL;
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

int	check_flag(char *arg)
{
	char	*flags[6];
	int		i;

	flags[0] = NULL;
	flags[1] = "--simple";
	flags[2] = "--medium";
	flags[3] = "--complex";
	flags[4] = "--adaptive";
	flags[5] = "--bench";
	i = 1;
	while (i < 6)
	{
		if (ft_strcmp(arg, flags[i]) == 0)
			return (i);
		i++;
	}
	return (0);
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

	args = ft_split(arg, ' ');
	if (!args)
		error_and_exit(NULL, NULL, bench);
	return (args);
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
