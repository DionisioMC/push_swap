/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:13:25 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/13 15:36:47 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;
	t_list	*first;
	t_list	*second;

	if (!stack)
	{
		return ;
	}
	if (ft_lstsize(*stack) <= 1)
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

void	swap_double(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
	{
		return ;
	}
	swap(stack_a);
	swap(stack_b);
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