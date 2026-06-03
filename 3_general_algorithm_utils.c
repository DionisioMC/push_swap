/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_general_algorithm_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:50:41 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/03 10:45:10 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	get_target_position(t_list **stack, int value)
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
		if (node->content > value && node->next->content < value)
			return (i + 1);
		else if (value >= max && node->next->content == max)
			return (i + 1);
		else if (value < min && node->next->content == min)
			return (i + 2);
		else if (value < min && node->content == min)
			return (i + 1);
		node = node->next;
		i++;
	}
	return (0);
}

void	rotate_b_to_top(t_list **b, int pos, t_bench *bench)
{
	int	size;
	int	i;

	if (!b)
		return ;
	size = ft_lstsize(*b);
	i = 0;
	if (pos <= (size - 1) / 2)
	{
		while (i++ < pos)
			rotate_b(b, bench);
	}
	else
	{
		while (i++ < size - pos)
			reverse_rotate_b(b, bench);
	}
}
