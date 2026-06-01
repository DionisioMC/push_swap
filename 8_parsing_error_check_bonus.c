/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_parsing_error_check_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:48:16 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 11:50:14 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

t_list	*parsing(char **args, char **argv)
{
	int		i;
	t_list	*a;
	int		content;

	i = 1;
	if (args != argv)
		i = 0;
	a = NULL;
	while (args[i])
	{
		content = (int) ft_atol(args[i]);
		ft_lstadd_back(&a, ft_lstnew(content));
		i++;
	}
	if (args != argv)
		free_args(args);
	if (!a)
		exit(0);
	return (a);
}
