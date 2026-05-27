/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:09:47 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/27 17:11:49 by dcoelho          ###   ########.fr       */
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

void	quicksort_a(t_list **a, t_list **b, t_bench *bench, int size)
{
	int	i;
	int	pivot;
	int	pushed;
	int	rotated;
	int	*array;

	if (size <= 3)
	{
		small_sort_a(a, bench, size);
		return;
	}
	i = 0;
	array = create_array(size, *a);
	if (!array)
		error_and_exit(a, b, bench);
	ft_sort_int_tab(array, size);
	pivot = array[size / 2];
	free(array);
	pushed = 0;
	rotated = 0;
	while (find_min(*a) < pivot)
	{
		if ((*a)->content < pivot)
		{
			push_b(b, a, bench);
			pushed++;
		}
		else
		{
			rotate_a(a, bench);
			rotated++;
		}
		i++;
	}
	while (rotated > 0)
	{
		reverse_rotate_a(a, bench);
		rotated--;
	} 
	quicksort_a(a, b, bench, size - pushed);
	quicksort_b(a, b, bench, pushed);
	while (pushed)
	{
		push_a(a, b, bench);
		pushed--;
	}
}

void	quicksort_b(t_list **a, t_list **b, t_bench *bench, int size)
{
	int	i;
	int	pivot;
	int	pushed;
	int	rotated;
	int	*array;

	if (size <= 3)
	{
		small_sort_b(b, bench, size);
		return;
	}
	i = 0;
	array = create_array(size, *b);
	if (!array)
		error_and_exit(a, b, bench);
	ft_sort_int_tab(array, size);
	pivot = array[size / 2];
	free(array);
	pushed = 0;
	rotated = 0;
	while (find_max(*b) >= pivot)
	{
		if ((*b)->content >= pivot)
		{
			push_a(a, b, bench);
			pushed++;
		}
		else
		{
			rotate_b(b, bench);
			rotated++;
		}
		i++;
	}
	while (rotated > 0)
	{
		reverse_rotate_b(b, bench);
		rotated--;
	}
	quicksort_a(a, b, bench, pushed);
	quicksort_b(a, b, bench, size - pushed);
	while (pushed)
    {
        push_b(b, a, bench);
        pushed--;
    }
}

void	quick_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*stack_a);
	quicksort_a(stack_a, stack_b, bench, size);
}
