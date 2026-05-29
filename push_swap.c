/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:28:32 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/29 14:57:54 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_algorithm(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	if (bench->disorder > 0)
	{
		if ((bench->strategy == 4 || bench->strategy == 0) && bench->disorder < 20)
			insertion_sort(stack_a, stack_b, bench);
		else if ((bench->strategy == 4 || bench->strategy == 0) && bench->disorder < 50)
			chunk_sort(stack_a, stack_b, bench);
		else if (bench->strategy == 4 || bench->strategy == 0)
			quick_sort(stack_a, stack_b, bench);
		else if (bench->strategy == 1)
			insertion_sort(stack_a, stack_b, bench);
		else if (bench->strategy == 2)
			chunk_sort(stack_a, stack_b, bench);
		else
			quick_sort(stack_a, stack_b, bench);
	}
	if (bench->flag == 1)
		ft_bench(bench);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(stack_b);
	free(bench);
}

int	main(int argc, char **argv)
{
	t_bench	*bench;
	t_list	*sa;
	t_list	**sb;
	char	**args;

	(void) argc;
	bench = ft_benchnew();
	args = ft_argv_split(argv, bench);
	error_flag_check(args, argv, bench);
	sa = parsing(args, argv, bench);
	bench->disorder = compute_disorder(sa);
	sb = malloc(sizeof(t_list *));
	if (!sb)
		error_and_exit(&sa, NULL, bench);
	*sb = NULL;
	//print_stack("sa", sa);
	select_algorithm(&sa, sb, bench);
	/* print_stack("sa", sa);
	print_stack("sb", *sb); */
	//ft_printf("%d\n", compute_disorder())
}
