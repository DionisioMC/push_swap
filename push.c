/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:20:43 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 16:02:38 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **source)
{
	t_list	*next_node;

	if (!source || !(*source))
		return ;
	next_node = (*source)->next;
	ft_lstadd_front(dest, *source);
	*source = next_node;
}

void	push_a(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
	bench->pa += 1;
}

void	push_b(t_list **stack_b, t_list **stack_a, t_bench *bench)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
	bench->pb += 1;
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
