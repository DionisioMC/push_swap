/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:09:47 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/27 11:17:23 by dcoelho          ###   ########.fr       */
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
		sort_three_b(b);
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
	while (i++ < size)
	{
		if ((*a)->content < pivot)
		{
			push(b, a);
			write(1, "pb\n", 3);
			pushed++;
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
			rotated++;
		}
	}
	while (rotated--)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	quicksort_a(a, b, bench, size - pushed);
	quicksort_b(a, b, bench, pushed);
	while (pushed--)
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
}

void	quicksort_b(t_list **a, t_list **b, t_bench *bench, int size)
{
	int	i;
	int	pivot;
	int	pushed;
	int	rotated;
	int	*array;

	i = 0;
	array = create_array(size, *b);
	if (!array)
		error_and_exit(a, b, bench);
	ft_sort_int_tab(array, size);
	pivot = array[size / 2];
	free(array);
	pushed = 0;
	rotated = 0;
	if (size <= 3)
	{
		small_sort_b(b, bench, size);
		return;
	}
	while (i++ < size)
	{
		if ((*b)->content >= pivot)
		{
			push(a, b);
			write(1, "pa\n", 3);
			pushed++;
		}
		else
		{
			rotate(b);
			write(1, "rb\n", 3);
			rotated++;
		}
	}
	while (rotated--)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	quicksort_a(a, b, bench, pushed);
	quicksort_b(a, b, bench, size - pushed);
}

void	quick_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*stack_a);
	quicksort_a(stack_a, stack_b, bench, size);
}
