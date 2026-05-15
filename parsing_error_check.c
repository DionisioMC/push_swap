/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:47:24 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/15 15:35:24 by hede-car         ###   ########.fr       */
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
			free(current->content);
			current->content = NULL;
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}

void	error_and_exit(t_list **sa, t_list **sb)
{
	if (!sa || *sa)
		ft_lstclear(sa);
	if (!sb || *sb)
		ft_lstclear(sb);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_flag_check(int argc, char **argv, int strategy, int bench)
{
	int	i;

	i = 0;
	while ()
}