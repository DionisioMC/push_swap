/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:48:27 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/21 17:32:56 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*create_array(int size, t_list *stack_a)
{
	int	*indexes;
	int	i;
	t_list	*node;

	indexes = malloc(size * sizeof(int));
	node = stack_a;
	if (!indexes)
		return (NULL);
	while (node)
	{
		indexes[i++] = node->content;
		node = node->next;
	}
	return (indexes);
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

int	*assign_indexes(int *indexes, t_list *stack_a, int size)
{
	t_list	*node;
	int		i;
	int		j;
	int		*arr;

	i = 0;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < size)
	{
		j = 0;
		node = stack_a;
		while (j < size)
		{
			if (node->content == indexes[j])
				arr[i] = j;
			j++;
			node = node->next;
		}
		i++;
	}
	free(indexes);
	return (arr);
}

#include <stdio.h>

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	num_chunks;
	int	*indexes;
	int	chunk_size;
	int	i;
	int	j;

	size = ft_lstsize(*stack_a);
	num_chunks = ft_sqrt(size);
	indexes = create_array(size, *stack_a);
	i = 0;
	if(!indexes)
		error_and_exit(stack_a, stack_b);
	ft_sort_int_tab(indexes, size);
	chunk_size = (size / num_chunks);
	while (i < num_chunks)
	{
		j = 0;
		while (j < chunk_size)
		{
			if (indexes[(chunk_size) * (i + 1) - 1] >= (*stack_a)->content)
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
		i++;
	}
	
	
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	int num_0 = 8;
	int num_1 = 1;
	int num_2 = 3;
	int num_3 = 2;
	int num_4 = 0;
	int num_5 = 5;
	ft_lstadd_back(&a, ft_lstnew(num_0));
	ft_lstadd_back(&a, ft_lstnew(num_1));
	ft_lstadd_back(&a, ft_lstnew(num_2));
	ft_lstadd_back(&a, ft_lstnew(num_3));
	ft_lstadd_back(&a, ft_lstnew(num_4));
	ft_lstadd_back(&a, ft_lstnew(num_5));
	printf("INITIAL\n");
	print_stack("A", a);
	print_stack("B", b);
	printf("===================\n");
	chunk_sort(&a, &b);
	printf("FINAL\n");
	print_stack("A", a);
	print_stack("B", b);
	ft_lstclear(&a);
}
