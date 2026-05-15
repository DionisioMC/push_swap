/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:39:19 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/15 15:27:07 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stack)
{
	int	max;

	max = *(stack->content);
	while (stack)
	{
		if (*(stack->content) > max)
			max = *(stack->content);
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_list *stack)
{
	int	min;

	min = *(stack->content);
	while (stack)
	{
		if (*(stack->content) < min)
			min = *(stack->content);
		stack = stack->next;
	}
	return (min);
}

int	get_target_position(t_list **stack_b, int value)
{
	int		i;
	t_list	*node;

	i = 0;
	if (!stack_b)
	return (0);
	node = *stack_b;
	while (node->next)
	{
		if (*(node->content) > value && *(node->next->content) < value)
			return (i + 1);

		node = node->next;
		i++;
	}
	if (value > find_max(node) || value < find_min(node))
		return (0);

	return (0);
}

void	rotate_b_to_top(t_list **stack_b, int pos)
{
	int	size;
	int	i;

	if (!stack_b)
		return ;
	size = ft_lstsize(*stack_b);
	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		i = 0;
		while (i++ < size - pos)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
		}
	}
}

void	insertion_sort(t_list **stack_a)
{
	t_list	**stack_b;
	t_list	*node;
	int		value;
	int		pos;

	node = *stack_a;
	stack_b = NULL;
	while (node)
	{
		value = *(node->content);
		pos = get_target_position(stack_b, value);
		rotate_b_to_top(stack_b, pos);
		push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	while (*stack_b)
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
}

#include <stdio.h>

void	print_stack(char *name, t_list *stack)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", *(stack->content));
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	int num_0 = 4;
	int num_1 = 1;
	int num_2 = 3;
	int num_3 = 2;
	int num_4 = 8;
	int num_5 = 5;
	ft_lstadd_back(&a, ft_lstnew(&num_0));
	ft_lstadd_back(&a, ft_lstnew(&num_1));
	ft_lstadd_back(&a, ft_lstnew(&num_2));
	ft_lstadd_back(&a, ft_lstnew(&num_3));
	ft_lstadd_back(&a, ft_lstnew(&num_4));
	ft_lstadd_back(&a, ft_lstnew(&num_5));
	printf("INITIAL\n");
	print_stack("A", a);
	print_stack("B", b);
	printf("===================\n");
	insertion_sort(&a);
	printf("FINAL\n");
	print_stack("A", a);
	print_stack("B", b);
}