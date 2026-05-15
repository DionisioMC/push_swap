/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:47:24 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/15 16:24:17 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (lst)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			free(current->content);
			current->content = NULL;
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}

void	error_and_exit(t_list **sa, t_list **sb)
{
	if (!sa || *sa)
		ft_lstclear(sa);
	if (!sb || *sb)
		ft_lstclear(sb);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_flag_check(int argc, char **argv, int strategy, int bench)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (check_flag(argv[i]))
		{
			if (check_flag(argv[i]) == 4)
				bench = 1;
			else
				strategy = check_flag(argv[i]);
		}
		else
		{
			if (!is_valid_num(argv[i]) || !is_int(argv[i]))
				error_and_exit(NULL, NULL);
		}
		i++;
	}
	if (!has_not_repeated(argv))
		error_and_exit(NULL, NULL);
}
