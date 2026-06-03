/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_rot_and_rev_rot_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:59:53 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/31 20:59:53 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	rotate(t_list **stack)
{
	t_list	*node;

	if (!stack || !(*stack))
		return ;
	node = *stack;
	ft_lstadd_back(stack, node);
	*stack = (*stack)->next;
	node->next = NULL;
}

void	rotate_double(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack || !(*stack))
		return ;
	node = *stack;
	while (node->next && node->next->next)
	{
		node = node->next;
	}
	last_node = node->next;
	node->next = NULL;
	ft_lstadd_front(stack, last_node);
}

void	reverse_rotate_double(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
}
