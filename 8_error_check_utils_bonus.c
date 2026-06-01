/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_error_check_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:54:19 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/01 14:33:57 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_check(char **args, char **argv)
{
	int	i;

	i = 0;
	if (args != argv)
		i = -1;
	while (args[++i])
	{
		if (!is_valid_num(args[i]) || !is_int(args[i]))
		{
			if (args != argv)
				free_args(args);
			error_and_exit(NULL, NULL);
		}
	}
	if (!has_not_repeated(args))
	{
		if (args != argv)
			free_args(args);
		error_and_exit(NULL, NULL);
	}
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	signal;

	i = 0;
	signal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signal *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i = i * 10 + *nptr - 48;
		nptr++;
	}
	return (i * signal);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while ((s1[n] == s2[n]) && (s1[n] != '\0'))
	{
		n++;
	}
	return (s1[n] - s2[n]);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (lst)
	{
		current = *lst;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
