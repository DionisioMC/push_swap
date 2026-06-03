/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   4_insertion.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: dcoelho <dcoelho@student.42porto.com>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/05/14 15:39:19 by dcoelho		   #+#	#+#			 */
/*   Updated: 2026/06/03 12:22:41 by dcoelho		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

t_move	best_move(t_list **a, t_list **b)
{
	t_list	*node;
	int		spc[6];
	t_move	best;
	t_move	current;

	spc[0] = ft_lstsize(*a);
	spc[1] = ft_lstsize(*b);
	best.total = INT_MAX;
	spc[3] = 0;
	node = *b;
	while (node)
	{
		spc[2] = get_target_position_a(a, node->content);
		spc[4] = calc_cost(spc[0], spc[2]);
		spc[5] = calc_cost(spc[1], spc[3]);
		current.cost_a = spc[4];
		current.cost_b = spc[5];
		current.total = ft_abs(spc[4]) + ft_abs(spc[5]);
		if (current.total < best.total)
			best = current;
		node = node->next;
		spc[3]++;
	}
	return (best);
}

void	execute_move(t_list **a, t_list **b, t_move mv, t_bench *bench)
{
	do_double_rotations(a, b, &mv, bench);
	while (mv.cost_a > 0)
	{
		rotate_a(a, bench);
		mv.cost_a--;
	}
	while (mv.cost_a < 0)
	{
		reverse_rotate_a(a, bench);
		mv.cost_a++;
	}
	while (mv.cost_b > 0)
	{
		rotate_b(b, bench);
		mv.cost_b--;
	}
	while (mv.cost_b < 0)
	{
		reverse_rotate_b(b, bench);
		mv.cost_b++;
	}
	push_a(a, b, bench);
}

void	rotate_a_to_top(t_list **a, int pos, t_bench *bench)
{
	int	size;
	int	i;

	if (!a)
		return ;
	size = ft_lstsize(*a);
	i = 0;
	if (pos <= (size - 1) / 2)
	{
		while (i++ < pos)
			rotate_a(a, bench);
	}
	else
	{
		while (i++ < size - pos)
			reverse_rotate_a(a, bench);
	}
}

void	insertion_sort(t_list **a, t_list **b, t_bench *bench)
{
	int		pos;
	int		size;
	int		prev;
	t_move	mv;

	size = ft_lstsize(*a);
	prev = (*a)->content;
	rotate_a(a, bench);
	while (--size)
	{
		if (prev < (*a)->content && (*a)->content < (*a)->next->content)
		{
			prev = (*a)->content;
			rotate_a(a, bench);
		}
		else
			push_b(b, a, bench);
	}
	while (*b)
	{
		mv = best_move(a, b);
		execute_move(a, b, mv, bench);
	}
	pos = get_target_position_a(a, find_min(*a));
	rotate_a_to_top(a, pos, bench);
}
