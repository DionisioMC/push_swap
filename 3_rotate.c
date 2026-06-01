/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:09:23 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:31:50 by hede-car         ###   ########.fr       */
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

void	rotate_double(t_list **a, t_list **b, t_bench *bench)
{
	if (!a || !b)
	{
		return ;
	}
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	bench->rr += 1;
}

void	rotate_a(t_list **a, t_bench *bench)
{
	rotate(a);
	write(1, "ra\n", 3);
	bench->ra += 1;
}

void	rotate_b(t_list **b, t_bench *bench)
{
	rotate(b);
	write(1, "rb\n", 3);
	bench->rb += 1;
}
