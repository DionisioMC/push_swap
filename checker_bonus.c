/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:45:55 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 10:10:59 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((unsigned char) s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}

char	**handle_str(char *arg)
{
	char	**args;

	args = ft_split(arg, ' ');
	if (!args)
		error_and_exit(NULL, NULL);
	return (args);
}

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

char	**ft_argv_split(char **argv)
{
	int		i;
	int		count;
	char	**args;

	i = 1;
	count = 0;
	args = NULL;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			args = handle_str(argv[i]);
		else
			count++;
		i++;
	}
	if (count > 0 && args)
	{
		free_args(args);
		error_and_exit(NULL, NULL);
	}
	if (args)
		return (args);
	return (argv);
}

void	do_move(char *move, t_list **a, t_list **b)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(move, "ss\n") == 0)
		swap_double(a, b);
	else if (ft_strcmp(move, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(move, "pb\n") == 0)
		push(b, a);
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(move, "rr\n") == 0)
		rotate_double(a, b);
	else if (ft_strcmp(move, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		reverse_rotate_double(a, b);
	else
		error_and_exit(a, b);
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
	write(2, "Error\n", 6);
	exit(1);
}

int	sorted_check(t_list *a)
{
	t_list	*fst_node;
	t_list	*scd_node;

	fst_node = a;
	while (fst_node->next)
	{
		scd_node = fst_node->next;
		if (fst_node->content > scd_node->content)
			return (0);
		fst_node = fst_node->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	**b;
	char	**args;
	char	*move;

	(void) argc;
	args = ft_argv_split(argv);
	error_flag_check(args, argv);
	a = parsing(args, argv);
	b = malloc(sizeof(t_list *));
	if (!b)
		error_and_exit(&a, NULL);
	*b = NULL;
	while (move = get_next_line(0))
		do_move(move, &a, b);
	if (sorted_check(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(a);
	ft_lstclear(b);
	free(b);
}
