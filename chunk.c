/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:48:27 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/22 19:12:13 by hede-car         ###   ########.fr       */
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
	int	*arr;
	int	i;
	t_list	*node;

	node = stack_a;
	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (node)
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


#include <stdio.h>

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	num_chunks;
	int	*arr;
	int	chunk_size;
	int	i;
	int	j;

	size = ft_lstsize(*stack_a);
	num_chunks = ft_sqrt(size);
	arr = create_array(size, *stack_a);
	if(!arr)
		error_and_exit(stack_a, stack_b);
	ft_sort_int_tab(arr, size);
	chunk_size = (size / num_chunks);
	i = 0;
	while (i < num_chunks)
	{
		j = 0;
		if (i < size % num_chunks)
		{
			while (j < chunk_size + 1)
			{
				if (arr[(chunk_size + 1) * (i + 1) - 1] >= (*stack_a)->content)
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
		else
		{
			while (j < chunk_size)
			{
				if (arr[(chunk_size) * (i + 1) - 1 + (size % num_chunks)] >= (*stack_a)->content)
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
		i++;
	}
	while(*stack_b)
	{
		rotate_b_to_top(stack_b, get_target_position(stack_b, find_max(*stack_b)));
		push(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	free(arr);
}

/* int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	int num_0 = 0;
	int num_1 = 1;
	int num_2 = 3;
	int num_3 = 9;
	int num_4 = 8;
	int num_5 = 5;
	int	num_6 = 2;
	int	num_7 = 4;
	ft_lstadd_back(&a, ft_lstnew(num_0));
	ft_lstadd_back(&a, ft_lstnew(num_1));
	ft_lstadd_back(&a, ft_lstnew(num_2));
	ft_lstadd_back(&a, ft_lstnew(num_3));
	ft_lstadd_back(&a, ft_lstnew(num_4));
	ft_lstadd_back(&a, ft_lstnew(num_5));
	ft_lstadd_back(&a, ft_lstnew(num_6));
	ft_lstadd_back(&a, ft_lstnew(num_7));
	printf("INITIAL\n");
	print_stack("A", a);
	print_stack("B", b);
	printf("===================\n");
	chunk_sort(&a, &b);
	printf("FINAL\n");
	print_stack("A", a);
	print_stack("B", b);
	ft_lstclear(&a);
} */
