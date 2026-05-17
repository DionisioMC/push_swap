/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:09:23 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/17 22:41:21 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*node;

	if (!stack || !(*stack))
	{
		return ;
	}
	node = *stack;
	ft_lstadd_back(stack, node);
	*stack = (*stack)->next;
	node->next = NULL;
}

void	rotate_double(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
	{
		return ;
	}
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack)
	{
		return ;
	}
	node = *stack;
	while (node->next->next)
	{
		node = node->next;
	}
	last_node = node->next;
	node->next = NULL;
	ft_lstadd_front(stack, last_node);
}

void	reverse_rotate_double(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
	{
		return ;
	}
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

/* #include <stdio.h>
int main()
{
	t_list	*list = ft_lstnew("batata");
	ft_lstadd_back(&list, ft_lstnew("banana"));
	reverse_rotate(&list);
	while(list)
	{
		printf("%s\n", (char *) list->content);
		list = list->next;
	}
} */