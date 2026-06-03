/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_string_handling_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:37:15 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/03 14:45:07 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**handle_str(char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		error_and_exit(NULL, NULL);
	return (args);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
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

int	do_move(char **move, t_list **a, t_list **b)
{
	if (ft_strcmp(*move, "sa\n") == 0)
		return (swap(a), 1);
	else if (ft_strcmp(*move, "sb\n") == 0)
		return (swap(b), 1);
	else if (ft_strcmp(*move, "ss\n") == 0)
		return (swap_double(a, b), 1);
	else if (ft_strcmp(*move, "pa\n") == 0)
		return (push(a, b), 1);
	else if (ft_strcmp(*move, "pb\n") == 0)
		return (push(b, a), 1);
	else if (ft_strcmp(*move, "ra\n") == 0)
		return (rotate(a), 1);
	else if (ft_strcmp(*move, "rb\n") == 0)
		return (rotate(b), 1);
	else if (ft_strcmp(*move, "rr\n") == 0)
		return (rotate_double(a, b), 1);
	else if (ft_strcmp(*move, "rra\n") == 0)
		return (reverse_rotate(a), 1);
	else if (ft_strcmp(*move, "rrb\n") == 0)
		return (reverse_rotate(b), 1);
	else if (ft_strcmp(*move, "rrr\n") == 0)
		return (reverse_rotate_double(a, b), 1);
	else
		return (0);
}
