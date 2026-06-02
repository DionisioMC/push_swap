/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_get_next_line_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoelho <dcoelho@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 12:06:55 by dcoelho           #+#    #+#             */
/*   Updated: 2026/06/02 11:59:50 by dcoelho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	int		i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		num++;
		i++;
	}
	return (num);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), NULL);
	i = -1;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	j;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (len > s_len - start)
		len = s_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*read_from_file(char *stash, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), NULL);
		else if (bytes_read == 0)
		{
			free(buffer);
			return (stash);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;
	int			i;

	i = 0;
	if (fd == -1)
		return (free(stash), NULL);
	stash = read_from_file(stash, fd);
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_substr(stash, 0, i + 1);
	temp = stash;
	stash = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(temp);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
