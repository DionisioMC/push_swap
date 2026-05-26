/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:13:25 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 14:34:05 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;
	t_list	*first;
	t_list	*second;

	if (!stack || !(*stack)->next)
	{
		return ;
	}
	first = *stack;
	second = first->next;
	temp = second->next;
	second->next = first;
	first->next = temp;
	*stack = second;
}

void	swap_double(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	if (!stack_a || !stack_b)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	bench->ss += 1;
}

void	swap_a(t_list **stack_a, t_bench *bench)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	bench->sa += 1;
}

void	swap_b(t_list **stack_b, t_bench *bench)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	bench->sb += 1;
}
/* #include <stdio.h>
int main()
{
	t_list	*list = ft_lstnew("batata");
	ft_lstadd_back(&list, ft_lstnew("banana"));
	swap(&list);
	while(list)
	{
		printf("%s\n", (char *) list->content);
		list = list->next;
	}
 */