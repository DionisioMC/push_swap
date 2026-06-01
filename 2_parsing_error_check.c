/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing_error_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:47:24 by hede-car          #+#    #+#             */
/*   Updated: 2026/06/01 14:41:56 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_check(char **args, char **argv, t_bench *bench)
{
	int	i;

	i = 0;
	if (args != argv)
		i = -1;
	while (args[++i])
	{
		if (check_flag(args[i]))
			continue ;
		else
		{
			if (!is_valid_num(args[i]) || !is_int(args[i]))
			{
				if (args != argv)
					free_args(args);
				error_and_exit(NULL, NULL, bench);
			}
		}
	}
	if (!has_not_repeated(args))
	{
		if (args != argv)
			free_args(args);
		error_and_exit(NULL, NULL, bench);
	}
}

t_list	*parsing(char **args, char **argv, t_bench *bench)
{
	int		i;
	t_list	*a;
	int		content;

	i = 1;
	if (args != argv)
		i = 0;
	a = NULL;
	while (args[i])
	{
		if (!check_flag(args[i]))
		{
			content = (int) ft_atol(args[i]);
			ft_lstadd_back(&a, ft_lstnew(content));
		}
		i++;
	}
	if (args != argv)
		free_args(args);
	if (!a)
	{
		free(bench);
		exit(0);
	}
	return (a);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}
