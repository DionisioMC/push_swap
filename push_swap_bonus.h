/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:30:38 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 11:06:40 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>

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
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
int		check_flag(char *arg);
int		is_valid_num(char *arg);
int		is_int(char *arg);
int		has_not_repeated(char **argv);
void	error_and_exit(t_list **a, t_list **b);
t_list	*parsing(char **args, char **argv);
void	error_check(char **args, char **argv);
int		ft_strcmp(char *s1, char *s2);
char	**ft_argv_split(char **argv);
void	free_args(char **args);

#endif