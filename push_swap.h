/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:27:48 by dcoelho           #+#    #+#             */
/*   Updated: 2026/05/19 15:02:46 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);
long	ft_atoi(const char *nptr);
void	swap(t_list **stack);
void	swap_double(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
int		check_flag(char *arg);
int		is_valid_num(char *arg);
int		is_int(char *arg);
int		has_not_repeated(int argc, char **argv);
void	error_and_exit(t_list **sa, t_list **sb);
t_list	*parsing(int argc, char **argv);
void	error_flag_check(int argc, char **argv, int *strategy, int *bench);
void	print_stack(char *name, t_list *stack);
int		ft_strcmp(char *s1, char *s2);

#endif