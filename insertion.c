/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:39:19 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 15:23:07 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
		if (node->content > value && node->next->content < value)
			return (i + 1);
		else if (value >= find_max(*stack)
			&& node->next->content == find_max(*stack))
			return (i + 1);
		else if (value < find_min(*stack)
			&& node->next->content == find_min(*stack))
			return (i + 2);
		node = node->next;
		i++;
	}
	return (0);
}

void	rotate_b_to_top(t_list **stack_b, int pos, t_bench *bench)
{
	int	size;
	int	i;

	if (!stack_b)
		return ;
	size = ft_lstsize(*stack_b);
	i = 0;
	if (pos <= (size - 1) / 2)
	{
		while (i++ < pos)
			rotate_b(stack_b, bench);
	}
	else
	{
		while (i++ < size - pos)
			reverse_rotate_b(stack_b, bench);
	}
}

void	insertion_sort(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*node;
	int		pos;

	node = *stack_a;
	while (*stack_a)
	{
		pos = get_target_position(stack_b, (*stack_a)->content);
		rotate_b_to_top(stack_b, pos, bench);
		push_b(stack_b, stack_a, bench);
	}
	pos = get_target_position(stack_b, find_max(*stack_b));
	rotate_b_to_top(stack_b, pos, bench);
	while (*stack_b)
		push_a(stack_a, stack_b, bench);
}

void	print_stack(char *name, t_list *stack)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->content);
		stack = stack->next;
	}
	printf("\n");
}

/* int	main(void)
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
	int num_6 = -1;
	ft_lstadd_back(&a, ft_lstnew(num_0));
	ft_lstadd_back(&a, ft_lstnew(num_1));
	ft_lstadd_back(&a, ft_lstnew(num_2));
	ft_lstadd_back(&a, ft_lstnew(num_3));
	ft_lstadd_back(&a, ft_lstnew(num_4));
	ft_lstadd_back(&a, ft_lstnew(num_5));
	ft_lstadd_back(&a, ft_lstnew(num_6));
	printf("INITIAL\n");
	print_stack("A", a);
	print_stack("B", b);
	printf("===================\n");
	insertion_sort(&a);
	printf("FINAL\n");
	print_stack("A", a);
	print_stack("B", b);
	ft_lstclear(&a);
} */
