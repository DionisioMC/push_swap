/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:28:32 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/02 16:55:41 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algorithm(t_list **a, t_list **b, t_bench *bench)
{
	if (bench->disorder > 0)
	{
		if ((bench->strategy == 4 || bench->strategy == 0)
			&& bench->disorder < 20)
			insertion_sort(a, b, bench);
		else if ((bench->strategy == 4 || bench->strategy == 0)
			&& bench->disorder < 50)
			chunk_sort(a, b, bench);
		else if (bench->strategy == 4 || bench->strategy == 0)
			quick_sort(a, b, bench);
		else if (bench->strategy == 1)
			insertion_sort(a, b, bench);
		else if (bench->strategy == 2)
			chunk_sort(a, b, bench);
		else
			quick_sort(a, b, bench);
	}
	if (bench->flag == 1)
		ft_bench(bench);
	ft_lstclear(a);
	ft_lstclear(b);
	free(b);
	free(bench);
}

void	select_small_algorithm(t_list **a, t_list **b, t_bench *bench)
{
	int	size;

	size = ft_lstsize(*a);
	if (bench->disorder > 0)
	{
		if (size == 5)
			sort_five(a, b, bench);
		else if (size == 4)
			sort_four(a, b, bench);
		else if (size == 3)
			sort_three(a, bench);
		else if (bench->strategy == 1)
			sort_two(a, bench);
	}
	if (bench->flag == 1)
		ft_bench(bench);
	ft_lstclear(a);
	ft_lstclear(b);
	free(b);
	free(bench);
}

int	main(int argc, char **argv)
{
	t_bench	*bench;
	t_list	*a;
	t_list	**b;
	char	**args;

	(void) argc;
	bench = ft_benchnew();
	args = ft_argv_split(argv, bench);
	error_check(args, argv, bench);
	a = parsing(args, argv, bench);
	bench->disorder = compute_disorder(a);
	b = malloc(sizeof(t_list *));
	if (!b)
		error_and_exit(&a, NULL, bench);
	*b = NULL;
	if (ft_lstsize(a) > 5)
		select_algorithm(&a, b, bench);
	else
		select_small_algorithm(&a, b, bench);
}
