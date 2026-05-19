/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:48:27 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/19 11:08:45 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sqroot(int i, int nb)
{
	if (i * i > nb)
		return (0);
	else if (i * i == nb)
		return (i);
	return (sqroot(i + 1, nb));
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
	{
		return (0);
	}
	return (sqroot(1, nb));
}

void	chunk_sort(t_list **stack_a)
{
	t_list	**stack_b;

	stack_b = NULL;
}