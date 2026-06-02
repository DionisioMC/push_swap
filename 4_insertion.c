/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_insertion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:39:19 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/02 15:07:21 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_list **a, t_list **b, t_bench *bench)
{
	int		pos;

	while (*a)
	{
		pos = get_target_position(b, (*a)->content);
		rotate_b_to_top(b, pos, bench);
		push_b(b, a, bench);
	}
	pos = get_target_position(b, find_max(*b));
	rotate_b_to_top(b, pos, bench);
	while (*b)
		push_a(a, b, bench);
}
