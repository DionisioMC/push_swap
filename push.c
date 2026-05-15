/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:20:43 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/15 17:48:29 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if (!stack_b)
	{
		return ;
	}
	node = *stack_b;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = node->next;
}

/* #include <stdio.h>
int main()
{
	t_list	*list_a = ft_lstnew("batata");
	t_list	*list_b = ft_lstnew("banana");
	push(&list_a, &list_b);
	while(list_a)
	{
		printf("%s\n", (char *) list_a->content);
		list_a = list_a->next;
	}
} */