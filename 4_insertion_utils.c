/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_insertion_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:47:57 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/03 14:21:27 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	calc_cost(int size, int pos)
{
	int	cost;

	if (pos <= size / 2)
		cost = pos;
	else
		cost = pos - size;
	return (cost);
}

int	get_target_position_a(t_list **stack, int value)
{
	int		i;
	t_list	*node;
	int		max;
	int		min;

	i = 0;
	if (!stack || !(*stack))
		return (0);
	max = find_max(*stack);
	min = find_min(*stack);
	node = *stack;
	while (node->next)
	{
		if (node->content < value && node->next->content > value)
			return (i + 1);
		else if (value <= min && node->next->content == min)
			return (i + 1);
		else if (value > max && node->next->content == max)
			return (i + 2);
		else if (value > max && node->content == max)
			return (i + 1);
		node = node->next;
		i++;
	}
	return (0);
}

void	do_double_rotations(t_list **a, t_list **b, t_move *mv, t_bench *bench)
{
	while (mv->cost_a > 0 && mv->cost_b > 0)
	{
		rotate_double(a, b, bench);
		mv->cost_a--;
		mv->cost_b--;
	}
	while (mv->cost_a < 0 && mv->cost_b < 0)
	{
		reverse_rotate_double(a, b, bench);
		mv->cost_a++;
		mv->cost_b++;
	}
}
