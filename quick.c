/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:09:47 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/28 17:31:50 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_a(t_list **a, t_bench *bench, int size)
{
	if (size == 2)
		sort_two_a(a, bench);
	else if (size == 3)
		sort_three_a(a, bench);
}

void	small_sort_b(t_list **b, t_bench *bench, int size)
{
	if (size == 2)
		sort_two_b(b, bench);
	else if (size == 3)
		sort_three_b(b, bench);
}

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

void	quick_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*stack_a);
	quicksort_a(stack_a, stack_b, bench, size);
}
