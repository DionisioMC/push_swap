/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:28:32 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 14:23:10 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_bench	*bench;
	t_list	*sa;
	t_list	**sb;
	char	**args;

	bench = ft_benchnew();
	args = ft_argv_split(argc, argv, bench->strategy, bench->flag);
	error_flag_check(args, argv, bench);
	sa = parsing(args, argv);
	bench->disorder = compute_disorder(sa);
	sb = malloc(sizeof(t_list *));
	if (!sb)
		error_and_exit(&sa, NULL, bench);
	*sb = NULL;
	error_flag_check(argc, argv, &strategy, &bench);
	sa = parsing(argc, argv);
	print_stack("sa", sa);
	quick_sort(&sa, sb);
	print_stack("sa", sa);
	print_stack("sb", *sb);
	//ft_printf("%d\n", compute_disorder())
}
