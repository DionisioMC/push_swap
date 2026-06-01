/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:13:25 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:33:29 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack)->next)
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

void	swap_double(t_list **a, t_list **b, t_bench *bench)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	bench->ss += 1;
}

void	swap_a(t_list **a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	bench->sa += 1;
}

void	swap_b(t_list **b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	bench->sb += 1;
}
