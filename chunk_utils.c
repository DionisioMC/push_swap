/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:58:08 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/23 23:04:15 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_chunks_even(int index, int chunk_size, int *indexes, t_list **stack_a, t_list **stack_b)
{
    int j;

    j = 0;
    while (j < chunk_size + 1)
    {
        if (indexes[index] >= (*stack_a)->content)
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

void    push_chunks_odd(int index, int chunk_size, int *indexes, t_list **stack_a, t_list **stack_b)
{
    int j;

    j = 0;
    while (j < chunk_size)
    {
        if (indexes[index] >= (*stack_a)->content)
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

void    organize_b(int num_chunks, int size, int *indexes, t_list **stack_a, t_list **stack_b)
{
    int i;
    int chunk_size;

    i = 0;
    chunk_size = (size / num_chunks);
    ft_sort_int_tab(indexes, size);
    while (i < num_chunks)
    {
        if (i < size % num_chunks)
            push_chunks_even((chunk_size + 1) * (i + 1) - 1, chunk_size, indexes, stack_a, stack_b);
        else
            push_chunks_odd((chunk_size) * (i + 1) - 1 + (size % num_chunks), chunk_size, indexes, stack_a, stack_b);
        i++;
    }
    free(indexes);
}