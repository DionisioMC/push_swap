/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:48:27 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/27 09:45:26 by hede-car         ###   ########.fr       */
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
	int		*arr;
	int		i;
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

void	chunk_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_chunk	chunk;
	int		*arr;
	t_list	**stacks[2];

	chunk.size = ft_lstsize(*stack_a);
	chunk.num_chunks = ft_sqrt(chunk.size);
	arr = create_array(chunk.size, *stack_a);
	if (!arr)
		error_and_exit(stack_a, stack_b, bench);
	stacks[0] = stack_a;
	stacks[1] = stack_b;
	organize_b(chunk, arr, stack_a, stack_b, bench);
	while (*stack_b)
	{
		rotate_b_to_top(stack_b,
			get_target_position(stack_b, find_max(*stack_b)), bench);
		push_a(stack_a, stack_b, bench);
	}
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
