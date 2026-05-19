/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:28:32 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/19 19:00:43 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		strategy;
	int		bench;
	t_list	*sa;
	t_list	**sb;

	strategy = 0;
	bench = 0;
	sb = NULL;
	error_flag_check(argc, argv, &strategy, &bench);
	sa = parsing(argc, argv);
	//print_stack("sa", sa);
	insertion_sort(&sa, sb);
	//print_stack("sa", sa);
}
