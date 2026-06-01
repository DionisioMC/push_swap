/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_general_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:09:06 by hede-car          #+#    #+#             */
/*   Updated: 2026/06/01 10:12:58 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(t_list **a, t_list **b, t_bench *bench)
{
	if (a && *a)
		ft_lstclear(a);
	if (b && *b)
	{
		ft_lstclear(b);
		free(b);
	}
	free(bench);
	write(2, "Error\n", 6);
	exit(1);
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
