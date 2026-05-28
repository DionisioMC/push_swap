/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:29:40 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/28 17:32:20 by dcoelho          ###   ########.fr       */
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

int	top(t_list *s)
{
	return (s->content);
}

int	second(t_list *s)
{
	return (s->next->content);
}

int	third(t_list *s)
{
	return (s->next->next->content);
}
