/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:58:08 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 14:39:06 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(int limit, int amount, t_list **stack_a, t_list **stack_b)
{
	int	j;

	j = 0;
	while (j < amount)
	{
		if (limit >= (*stack_a)->content)
		{
			push(stack_b, stack_a);
			write(1, "pb\n", 3);
			j++;
		}
		else
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
}

int	get_chunk_amount(int i, int chunk_size, int remainder)
{
	if (i < remainder)
		return (chunk_size + 1);
	return (chunk_size);
}

int	calculate_limit_index(int i, int chunk_size, int remainder)
{
	if (i < remainder)
		return ((chunk_size + 1) * (i + 1) - 1);
	return ((chunk_size * (i + 1)) - 1 + remainder);
}

void	organize_b(t_chunk chunk,
	int *indexes, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	limit;
	int	amount;
	int	limit_index;

	i = 0;
	ft_sort_int_tab(indexes, chunk.size);
	while (i < chunk.num_chunks)
	{
		amount = get_chunk_amount(i,
				chunk.size / chunk.num_chunks, chunk.size % chunk.num_chunks);
		limit_index = calculate_limit_index(i,
				chunk.size / chunk.num_chunks, chunk.size % chunk.num_chunks);
		limit = indexes[limit_index];
		push_chunks(limit, amount, stack_a, stack_b);
		i++;
	}
	free(indexes);
}
