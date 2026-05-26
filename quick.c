/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:09:47 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 16:14:50 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort_a(t_list **a, int size)
{
	if (size == 2)
		sort_two_a(a);
	else if (size == 3)
		sort_three_a(a);
}

void	small_sort_b(t_list **b, int size)
{
	if (size == 2)
		sort_two_b(b);
	else if (size == 3)
		sort_three_b(b);
}

void	quicksort_a(t_list **a, t_list **b, int size)
{
	int	i;
	int	pivot;
	int	pushed;
	int	rotated;
	int	*array;

	if (size <= 3)
	{
		small_sort_a(a, size);
		return;
	}
	i = 0;
	array = create_array(size, *a);
	if (!array)
		error_and_exit(a, b);
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
	quicksort_a(a, b, size - pushed);
	quicksort_b(a, b, pushed);
	while (pushed--)
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
}

void	quicksort_b(t_list **a, t_list **b, int size)
{
	int	i;
	int	pivot;
	int	pushed;
	int	rotated;
	int	*array;

	i = 0;
	array = create_array(size, *b);
	if (!array)
		error_and_exit(a, b);
	ft_sort_int_tab(array, size);
	pivot = array[size / 2];
	free(array);
	pushed = 0;
	rotated = 0;
	if (size <= 3)
	{
		small_sort_b(b, size);
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
	quicksort_a(a, b, pushed);
	quicksort_b(a, b, size - pushed);
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	quicksort_a(stack_a, stack_b, size);
}
