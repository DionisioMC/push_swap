/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:48:13 by hede-car          #+#    #+#             */
/*   Updated: 2026/06/03 14:06:20 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*last_node;

	if (!stack || !(*stack))
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

void	reverse_rotate_double(t_list **a,
	t_list **b, t_bench *bench)
{
	if (!a || !b)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	bench->rrr += 1;
}

void	reverse_rotate_a(t_list **a, t_bench *bench)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	bench->rra += 1;
}

void	reverse_rotate_b(t_list **b, t_bench *bench)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	bench->rrb += 1;
}
