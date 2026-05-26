/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:29:40 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 16:12:11 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

void	sort_three_a(t_list **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->content;
	y = (*a)->next->content;
	z = (*a)->next->next->content;
	if (x > y && y < z && x < z)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (x > y && y > z)
	{
		swap(a);
		write(1, "sa\n", 3);
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (x > y && y < z && x > z)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (x < y && y > z && x < z)
	{
		swap(a);
		write(1, "sa\n", 3);
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (x < y && y > z && x > z)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	sort_two_b(t_list **b)
{
	if ((*b)->content < (*b)->next->content)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
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
