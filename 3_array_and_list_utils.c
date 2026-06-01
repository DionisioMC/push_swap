/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_array_and_list_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:42:14 by hede-car          #+#    #+#             */
/*   Updated: 2026/06/01 11:02:00 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_array(int size, t_list *a)
{
	int		*arr;
	int		i;
	t_list	*node;

	node = a;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (node && i < size)
	{
		arr[i++] = node->content;
		node = node->next;
	}
	return (arr);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
