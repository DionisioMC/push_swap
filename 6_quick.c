/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_quick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:09:47 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:50:23 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a(t_list **a, t_list **b, t_bench *bench, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;

	if (size <= 3)
	{
		small_sort_a(a, bench, size);
		return ;
	}
	pivot = assign_pivot(a, b, bench, size);
	pushed = 0;
	rotated = 0;
	while (find_min(*a) < pivot)
	{
		if ((*a)->content < pivot && ++pushed)
			push_b(b, a, bench);
		else if (++rotated)
			rotate_a(a, bench);
	}
	while (rotated--)
		reverse_rotate_a(a, bench);
	quicksort_a(a, b, bench, size - pushed);
	quicksort_b(a, b, bench, pushed);
	while (pushed--)
		push_a(a, b, bench);
}

void	quicksort_b(t_list **a, t_list **b, t_bench *bench, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;

	if (size <= 3)
	{
		small_sort_b(b, bench, size);
		return ;
	}
	pivot = assign_pivot(b, a, bench, size);
	pushed = 0;
	rotated = 0;
	while (find_max(*b) >= pivot)
	{
		if ((*b)->content >= pivot && ++pushed)
			push_a(a, b, bench);
		else if (++rotated)
			rotate_b(b, bench);
	}
	while (rotated--)
		reverse_rotate_b(b, bench);
	quicksort_a(a, b, bench, pushed);
	quicksort_b(a, b, bench, size - pushed);
	while (pushed--)
		push_b(b, a, bench);
}

void	quick_sort(t_list **a, t_list **b, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*a);
	quicksort_a(a, b, bench, size);
}
