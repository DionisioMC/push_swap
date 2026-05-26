/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:09:23 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 14:48:42 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*node;

	if (!stack || !(*stack))
	{
		return ;
	}
	node = *stack;
	ft_lstadd_back(stack, node);
	*stack = (*stack)->next;
	node->next = NULL;
}

void	rotate_double(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	if (!stack_a || !stack_b)
	{
		return ;
	}
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	bench->rr += 1;
}

void	rotate_a(t_list **stack_a, t_bench *bench)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	bench->ra += 1;
}

void	rotate_b(t_list **stack_b, t_bench *bench)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	bench->rb += 1;
}

/* #include <stdio.h>
int main()
{
	t_list	*list = ft_lstnew("batata");
	ft_lstadd_back(&list, ft_lstnew("banana"));
	reverse_rotate(&list);
	while(list)
	{
		printf("%s\n", (char *) list->content);
		list = list->next;
	}
} */