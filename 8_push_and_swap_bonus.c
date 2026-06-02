/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_push_and_swap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:57:08 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/31 20:57:08 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	push(t_list **dest, t_list **source)
{
	t_list	*next_node;

	if (!source || !(*source))
		return ;
	next_node = (*source)->next;
	ft_lstadd_front(dest, *source);
	*source = next_node;
}

void	swap(t_list **stack)
{
	t_list	*temp;
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		return ;
	}
	first = *stack;
	second = first->next;
	temp = second->next;
	second->next = first;
	first->next = temp;
	*stack = second;
}

void	swap_double(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}
