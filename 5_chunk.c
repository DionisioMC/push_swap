/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_chunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:48:27 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:47:03 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_list **a, t_list **b, t_bench *bench)
{
	t_chunk	chunk;
	int		*arr;
	t_list	**stacks[2];

	chunk.size = ft_lstsize(*a);
	chunk.num_chunks = ft_sqrt(chunk.size);
	arr = create_array(chunk.size, *a);
	if (!arr)
		error_and_exit(a, b, bench);
	stacks[0] = a;
	stacks[1] = b;
	organize_b(chunk, arr, stacks, bench);
	while (*b)
	{
		rotate_b_to_top(b,
			get_target_position(b, find_max(*b)), bench);
		push_a(a, b, bench);
	}
}
