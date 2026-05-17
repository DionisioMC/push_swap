/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:20:43 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/17 19:49:25 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*next_node;

	if (!b)
	{
		return ;
	}
	next_node = (*b)->next,
	ft_lstadd_front(a, *b);
	*b = next_node;
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