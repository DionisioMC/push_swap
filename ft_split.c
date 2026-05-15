/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hede-car <hede-car@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:17:13 by hede-car          #+#    #+#             */
/*   Updated: 2026/05/15 15:34:51 by hede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_create_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free_matrix(char **matrix, int j)
{
	while (j >= 0)
		free(matrix[j--]);
	free(matrix);
	return (NULL);
}

static char	**ft_create_matrix(char	**matrix, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			matrix[j] = ft_create_word(&s[i], c);
			if (!matrix[j])
				return (ft_free_matrix(matrix, j - 1));
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	matrix[j] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;

	if (!s)
		return (NULL);
	matrix = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	return (ft_create_matrix(matrix, s, c));
}
