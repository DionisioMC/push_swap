/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:13:04 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/14 17:12:13 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	is_flag(char *arg)
{
	char	*flags[5];
	int		i;

	flags[0] = "--simple";
	flags[1] = "--medium";
	flags[2] = "--complex";
	flags[3] = "--adaptive";
	flags[4] = "--bench";
	i = 0;
	while (i < 5)
	{
		if (arg == flags[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_num(char *arg)
{
	int	i;

	i = 0;
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

int	is_not_long(char *arg)
{
	long	num;

	num = ft_atoi(arg);
	if (num < (long) INT_MIN || num > (long) INT_MAX)
		return (0);
	return (1);
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

int	has_not_repeated(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < argc - 1)
	{
		if (!is_flag(argv[i]))
		{
			j = i + 1;
			while (j < argc)
			{
				if (remove_zeros(argv[i]) == remove_zeros(argv[j]))
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}
