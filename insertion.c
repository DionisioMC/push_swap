/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:39:19 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/17 23:15:31 by dcoelho          ###   ########.fr       */
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

int	get_target_position(t_list **stack, int value)
{
	int		i;
	t_list	*node;

	i = 0;
	if (!stack)
		return (0);
	node = *stack;
	while (node->next)
	{
		if (*(node->content) > value && *(node->next->content) < value)
			return (i);
		node = node->next;
		i++;
	}
	return (0);
}

void	rotate_b_to_top(t_list **stack_b, int pos)
{
	int	size;
	int	i;

	if (!stack_b)
		return ;
	size = ft_lstsize(*stack_b);
	i = 0;
	if (pos <= size / 2)
	{
		while (i++ < pos)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while (i++ < size - pos)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
		}
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

void	insertion_sort(t_list **stack_a)
{
	t_list	**stack_b;
	t_list	*node;
	int		value;
	int		pos;

	node = *stack_a;
	stack_b = NULL;
	while (*stack_a)
	{
		value = *((*stack_a)->content);
		pos = get_target_position(stack_b, value);
		rotate_b_to_top(stack_b, pos);
		if (stack_b)
		{
			push(stack_b, stack_a);
		}
		else
		{
			*stack_a = (*stack_a)->next;
			stack_b = &node;
			node->next = NULL;
		}
		print_stack("A", *stack_a);
		print_stack("B", *stack_b);
		//write(1, "pb\n", 3);
	}
	while (*stack_b)
	{
		push(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
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