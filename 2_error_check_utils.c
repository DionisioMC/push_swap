/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_error_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:13:04 by hede-car          #+#    #+#             */
/*   Updated: 2026/06/01 10:28:12 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	num = ft_atol(arg);
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
		if (!check_flag(argv[i]))
		{
			j = i + 1;
			while (argv[j])
			{
				if (ft_strcmp(remove_zeros(argv[i]), remove_zeros(argv[j]))
					== 0)
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

long	ft_atol(const char *nptr)
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
