/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 23:09:47 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/23 23:13:05 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    chunk_sort(t_list **stack_a, t_list **stack_b)
{
    int size;
    int *array;

    size = ft_lstsize(*stack_a);
    array = create_array(size, *stack_a);
}