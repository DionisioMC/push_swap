/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_checker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:45:55 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/03 14:34:58 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	handle_move(char **move, t_list **a, t_list **b)
{
	*move = get_next_line(0);
	while (move && *move)
	{
		if (!do_move(move, a, b))
		{
			free(*move);
			error_and_exit(a, b);
		}
		free(*move);
		*move = get_next_line(0);
	}
}

void	error_and_exit(t_list **a, t_list **b)
{
	if (a && *a)
		ft_lstclear(a);
	if (b && *b)
	{
		ft_lstclear(b);
		free(b);
	}
	else if (b && !(*b))
	{
		free(b);
	}
	get_next_line(-1);
	write(2, "Error\n", 6);
	exit(1);
}

int	sorted_check(t_list *a)
{
	t_list	*fst_node;
	t_list	*scd_node;

	fst_node = a;
	while (fst_node && fst_node->next)
	{
		scd_node = fst_node->next;
		if (fst_node->content > scd_node->content)
			return (0);
		fst_node = fst_node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	**b;
	char	**args;
	char	*move;

	args = ft_argv_split(argv);
	error_check(args, argv);
	a = parsing(args, argv);
	b = malloc(sizeof(t_list *));
	if (!b && argc)
		error_and_exit(&a, NULL);
	*b = NULL;
	handle_move(&move, &a, b);
	if (sorted_check(a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	ft_lstclear(b);
	free(b);
}
