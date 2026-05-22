/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:15:35 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/21 19:17:12 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	ft_movesnew(void)
{
	t_moves	moves;
	
	moves.sa = 0;
	moves.sb = 0;
	moves.ss = 0;
	moves.pa = 0;
	moves.pb = 0;
	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rrr = 0;
	return (moves);
}

double	compute_disorder(t_list *sa)
{
	double	mistakes;
	double	total_pairs;
	t_list	*fst_node;
	t_list	*scd_node;

	mistakes = 0;
	total_pairs = 0;
	fst_node = sa;
	while (fst_node->next)
	{
		scd_node = fst_node->next;
		while (scd_node)
		{
			total_pairs += 1;
			if (fst_node->content > scd_node->content)
				mistakes += 1;
			scd_node = scd_node->next;
		}
		fst_node = fst_node->next;
	}
	return (mistakes / total_pairs * 100);
}

void	ft_bench(double disorder, int strategy, t_moves moves)
{
	int	total;

	total = moves.sa + moves.sb + moves.ss + moves.pa + moves.pb + moves.ra
		+ moves.rb + moves.rr + moves.rra + moves.rrb + moves.rrr;
	ft_printf("[bench] disorder: %f\n", disorder);
	ft_printf("[bench] strategy: ");
	if ((strategy == 4 || strategy == 0) && disorder < 20)
		ft_printf("Adaptive / O(n²)\n");
	else if ((strategy == 4 || strategy == 0) && disorder < 50)
		ft_printf("Adaptive / O(n√n)\n");
	else if (strategy == 4 || strategy == 0)
		ft_printf("Adaptive / O(nlogn)\n");
	else if (strategy == 1)
		ft_printf("Simple / O(n²)\n");
	else if (strategy == 2)
		ft_printf("Medium / O(n√n)\n");
	else
		ft_printf("Complex / O(nlogn)\n");
	ft_printf("[bench] total_ops: %d\n", total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", moves.sa,
		moves.sb, moves.ss, moves.pa, moves.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		moves.ra, moves.rb, moves.rr, moves.rra, moves.rrb, moves.rrr);
}
