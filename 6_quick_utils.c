/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_quick_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:29:40 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:51:57 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign_pivot(t_list **a, t_list **b, t_bench *bench, int size)
{
	int	*array;
	int	pivot;

	array = create_array(size, *a);
	if (!array)
		error_and_exit(a, b, bench);
	ft_sort_int_tab(array, size);
	pivot = array[size / 2];
	free(array);
	return (pivot);
}

void	sort_two_a(t_list **a, t_bench *bench)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(a, bench);
}

void	sort_three_a(t_list **a, t_bench *bench)
{
	if (top(*a) > second(*a) && second(*a) < third(*a) && top(*a) < third(*a))
		swap_a(a, bench);
	else if (top(*a) > second(*a))
	{
		if (second(*a) > third(*a))
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
	else if (top(*a) < second(*a) && second(*a) > third(*a))
	{
		rotate_a(a, bench);
		swap_a(a, bench);
		reverse_rotate_a(a, bench);
		if (top(*a) > third(*a))
			swap_a(a, bench);
	}
}

void	sort_two_b(t_list **b, t_bench *bench)
{
	if ((*b)->content < (*b)->next->content)
		swap_b(b, bench);
}

void	sort_three_b(t_list **b, t_bench *bench)
{
	if (top(*b) < second(*b) && second(*b) > third(*b) && top(*b) > third(*b))
		swap_b(b, bench);
	else if (top(*b) < second(*b))
	{
		if (second(*b) < third(*b))
		{
			rotate_b(b, bench);
			swap_b(b, bench);
			reverse_rotate_b(b, bench);
		}
		swap_b(b, bench);
		rotate_b(b, bench);
		swap_b(b, bench);
		reverse_rotate_b(b, bench);
	}
	else if (top(*b) > second(*b) && second(*b) < third(*b))
	{
		rotate_b(b, bench);
		swap_b(b, bench);
		reverse_rotate_b(b, bench);
		if (top(*b) < third(*b))
			swap_b(b, bench);
	}
}
