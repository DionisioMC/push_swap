/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:20:43 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/22 11:46:23 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dest, t_list **source)
{
	t_list	*next_node;

	if (!source)
		return ;
	next_node = (*source)->next;
	ft_lstadd_front(dest, *source);
	*source = next_node;
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
