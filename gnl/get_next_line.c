/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:30:20 by chruhin           #+#    #+#             */
/*   Updated: 2023/10/12 10:01:03 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	size_t		bytes_read;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (line)
			free(line);
		line = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while ((ft_strchr(line, '\n') == NULL) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (ft_split_first_line(line, &line));
}

char	*ft_strchr(const char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != c)
		s++;
	if (*s == c)
		return ((char *) s);
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 0;
	j = 0;
	if (!s2 && !s1)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new_str)
		return (NULL);
	if (s1)
		while (s1[i])
			new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_split_first_line(char *s, char **rest)
{
	size_t	i;
	char	*first_line;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	first_line = ft_substr(s, 0, i + 1);
	if (rest)
	{
		if (s[i] == '\n' && s[i + 1])
			*rest = ft_substr(s, i + 1, ft_strlen(s) - i - 1);
		else
			*rest = NULL;
	}
	free(s);
	return (first_line);
}
