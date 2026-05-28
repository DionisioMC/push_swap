/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:48:13 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/28 16:18:32 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack)
		return ;
	node = *stack;
	while (node->next->next)
	{
		node = node->next;
	}
	last_node = node->next;
	node->next = NULL;
	ft_lstadd_front(stack, last_node);
}

void	reverse_rotate_double(t_list **stack_a,
	t_list **stack_b, t_bench *bench)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	bench->rrr += 1;
}

void	reverse_rotate_a(t_list **stack_a, t_bench *bench)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	bench->rra += 1;
}

void	reverse_rotate_b(t_list **stack_b, t_bench *bench)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	bench->rrb += 1;
}
