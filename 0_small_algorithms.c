/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_small_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:14:43 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/02 19:09:31 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **a, t_bench *bench)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(a, bench);
}

void	sort_three(t_list **a, t_bench *bench)
{
	if (top(*a) > second(*a) && second(*a) < third(*a) && top(*a) < third(*a))
		swap_a(a, bench);
	else if (top(*a) < second(*a) && second(*a) > third(*a)
		&& top(*a) < third(*a))
	{
		swap_a(a, bench);
		rotate_a(a, bench);
	}
	else if (top(*a) < second(*a) && second(*a) > third(*a)
		&& top(*a) > third(*a))
		reverse_rotate_a(a, bench);
	else if (top(*a) > second(*a) && second(*a) > third(*a)
		&& top(*a) > third(*a))
	{
		swap_a(a, bench);
		reverse_rotate_a(a, bench);
	}
	else if (top(*a) > second(*a) && second(*a) < third(*a)
		&& top(*a) > third(*a))
		rotate_a(a, bench);
}

void	sort_four(t_list **a, t_list **b, t_bench *bench)
{
	int	*array;
	int	pivot;

	array = create_array(4, *a);
	if (!array)
		error_and_exit(a, b, bench);
	ft_sort_int_tab(array, 4);
	pivot = array[2];
	free(array);
	while (find_min(*a) < pivot)
	{
		if ((*a)->content < pivot)
			push_b(b, a, bench);
		else
			rotate_a(a, bench);
	}
	sort_two(a, bench);
	if ((*b)->content < (*b)->next->content)
		swap_b(b, bench);
	push_a(a, b, bench);
	push_a(a, b, bench);
}

void	sort_five(t_list **a, t_list **b, t_bench *bench)
{
	int	*array;
	int	pivot;

	array = create_array(5, *a);
	if (!array)
		error_and_exit(a, b, bench);
	ft_sort_int_tab(array, 5);
	pivot = array[2];
	free(array);
	while (find_min(*a) < pivot)
	{
		if ((*a)->content < pivot)
			push_b(b, a, bench);
		else
			rotate_a(a, bench);
	}
	sort_three(a, bench);
	if ((*b)->content < (*b)->next->content)
		swap_b(b, bench);
	push_a(a, b, bench);
	push_a(a, b, bench);
}
