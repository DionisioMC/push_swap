/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_chunk_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:58:08 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:46:22 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(int limit, int amount, t_list **stacks[2], t_bench *bench)
{
	int	j;

	j = 0;
	while (j < amount)
	{
		if (limit >= (*stacks[0])->content)
		{
			push_b(stacks[1], stacks[0], bench);
			j++;
		}
		else
			rotate_a(stacks[0], bench);
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

void	organize_b(t_chunk chunk, int *arr, t_list **stacks[2], t_bench *bench)
{
	int	i;
	int	limit;
	int	amount;
	int	limit_index;

	i = 0;
	ft_sort_int_tab(arr, chunk.size);
	while (i < chunk.num_chunks)
	{
		amount = get_chunk_amount(i,
				chunk.size / chunk.num_chunks, chunk.size % chunk.num_chunks);
		limit_index = calculate_limit_index(i,
				chunk.size / chunk.num_chunks, chunk.size % chunk.num_chunks);
		limit = arr[limit_index];
		push_chunks(limit, amount, stacks, bench);
		i++;
	}
	free(arr);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i <= nb)
		i++;
	return (i - 1);
}
