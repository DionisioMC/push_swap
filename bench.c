/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:15:35 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/26 14:17:27 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*ft_benchnew(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (!bench)
		error_and_exit(NULL, NULL, bench);
	bench->flag = 0;
	bench->strategy = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	return (bench);
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

void	ft_bench(double disorder, t_bench *bench)
{
	int	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
		+ bench->rrr;
	ft_printf("[bench] disorder: %f\n", disorder);
	ft_printf("[bench] strategy: ");
	if ((bench->strategy == 4 || bench->strategy == 0) && disorder < 20)
		ft_printf("Adaptive / O(n²)\n");
	else if ((bench->strategy == 4 || bench->strategy == 0) && disorder < 50)
		ft_printf("Adaptive / O(n√n)\n");
	else if (bench->strategy == 4 || bench->strategy == 0)
		ft_printf("Adaptive / O(nlogn)\n");
	else if (bench->strategy == 1)
		ft_printf("Simple / O(n²)\n");
	else if (bench->strategy == 2)
		ft_printf("Medium / O(n√n)\n");
	else
		ft_printf("Complex / O(nlogn)\n");
	ft_printf("[bench] total_ops: %d\n", total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", bench->sa,
		bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
