/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:27:48 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/26 15:16:39 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_bench
{
	int	flag;
	int	strategy;
	int	disorder;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_chunk
{
	int	size;
	int	num_chunks;
}	t_chunk;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
long	ft_atoi(const char *nptr);
void	swap_double(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	swap_a(t_list **stack_a, t_bench *bench);
void	swap_b(t_list **stack_b, t_bench *bench);
void	push_a(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	push_b(t_list **stack_b, t_list **stack_a, t_bench *bench);
void	rotate_double(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	rotate_a(t_list **stack_a, t_bench *bench);
void	rotate_b(t_list **stack_b, t_bench *bench);
void	reverse_rotate_double(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	reverse_rotate_a(t_list **stack_a, t_bench *bench);
void	reverse_rotate_b(t_list **stack_b, t_bench *bench);
char	**ft_split(char const *s, char c);
int		check_flag(char *arg);
int		is_valid_num(char *arg);
int		is_int(char *arg);
int		has_not_repeated(char **argv);
void	error_and_exit(t_list **sa, t_list **sb, t_bench *bench);
t_list	*parsing(char **argv, char **args);
void	error_flag_check(char** args, char **argv, t_bench *bench);
void	print_stack(char *name, t_list *stack);
int		ft_strcmp(char *s1, char *s2);
void	ft_printf(const char *format, ...);
double	compute_disorder(t_list *sa);
void	insertion_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
int		find_max(t_list *stack);
int		find_min(t_list *stack);
void	rotate_b_to_top(t_list **stack_b, int pos, t_bench *bench);
int		get_target_position(t_list **stack, int value);
void	chunk_sort(t_list **stack_a, t_list **stack_b);
void	organize_b(t_chunk chunk,
			int *indexes, t_list **stack_a, t_list **stack_b);
void	ft_sort_int_tab(int *tab, int size);
int		*create_array(int size, t_list *stack_a);
void	quick_sort(t_list **stack_a, t_list **stack_b);
void	sort_two_a(t_list **a);
void	sort_two_b(t_list **b);
void	sort_three_a(t_list **a);
void	sort_three_b(t_list **b);
void	quicksort_a(t_list **a, t_list **b, int size);
void	quicksort_b(t_list **a, t_list **b, int size);

#endif