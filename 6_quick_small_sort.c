/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_quick_small_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:51:09 by hede-car          #+#    #+#             */
/*   Updated: 2026/06/01 10:52:09 by hede-car         ###   ########.fr       */
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
