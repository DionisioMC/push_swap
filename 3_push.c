/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:20:43 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:43:42 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **source)
{
	t_list	*next_node;

	if (!source || !(*source))
		return ;
	next_node = (*source)->next;
	ft_lstadd_front(dest, *source);
	*source = next_node;
}

void	push_a(t_list **a, t_list **b, t_bench *bench)
{
	push(a, b);
	write(1, "pa\n", 3);
	bench->pa += 1;
}

void	push_b(t_list **b, t_list **a, t_bench *bench)
{
	push(b, a);
	write(1, "pb\n", 3);
	bench->pb += 1;
}
