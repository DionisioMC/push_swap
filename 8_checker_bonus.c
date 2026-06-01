/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_checker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:45:55 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 17:44:32 by dcoelho          ###   ########.fr       */
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

void	do_move(char **move, t_list **a, t_list **b)
{
	if (ft_strcmp(*move, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(*move, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(*move, "ss\n") == 0)
		swap_double(a, b);
	else if (ft_strcmp(*move, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(*move, "pb\n") == 0)
		push(b, a);
	else if (ft_strcmp(*move, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(*move, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(*move, "rr\n") == 0)
		rotate_double(a, b);
	else if (ft_strcmp(*move, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(*move, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(*move, "rrr\n") == 0)
		reverse_rotate_double(a, b);
	else
	{
		free(*move);
		error_and_exit(a, b);
	}
	free(*move);
	*move = get_next_line(0);
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
	else if (!(*b))
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
	move = get_next_line(0);
	while (move)
	{
		do_move(&move, &a, b);
	}
	if (sorted_check(a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	ft_lstclear(b);
	free(b);
}
