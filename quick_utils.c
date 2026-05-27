/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:29:40 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/27 11:12:04 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_list **a, t_bench *bench)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(a, bench);
}

void	sort_three_a(t_list **a, t_bench *bench)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->content;
	y = (*a)->next->content;
	z = (*a)->next->next->content;
	if (x > y && y < z && x < z)
		swap_a(a, bench);
	else if (x > y)
	{
		if (y > z)
		{
			rotate_a(a, bench);
			swap_a(a, bench);
			reverse_rotate_a(a, bench);
		}
		swap_a(a, bench);
		rotate_a(a, bench);
		swap_a(a, bench);
		reverse_rotate_a(a, bench);
	}
	else if (x < y && y > z)
	{
		rotate_a(a, bench);
		swap_a(a, bench);
		reverse_rotate_a(a, bench);
		if (x > z)
			swap_a(a, bench);
	}
}

void	sort_two_b(t_list **b, t_bench *bench)
{
	if ((*b)->content < (*b)->next->content)
		swap_b(b, bench);
}

void	sort_three_b(t_list **b)
{
	int	x;
	int	y;
	int	z;

	x = (*b)->content;
	y = (*b)->next->content;
	z = (*b)->next->next->content;
	if (x < y && y < z)
	{
		swap(b);
		write(1, "sb\n", 3);
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	else if (x < y && y > z && x < z)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	else if (x > y && y < z && x < z)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (x < y && y > z && x > z)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	else if (x > y && y < z && x > z)
	{
		swap(b);
		write(1, "sb\n", 3);
		rotate(b);
		write(1, "rb\n", 3);
	}
}
