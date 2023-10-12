/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:58:37 by chruhin           #+#    #+#             */
/*   Updated: 2023/07/26 13:18:44 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int position, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*substr;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (position >= slen)
		return (NULL);
	if (len >= slen)
		len = slen - position;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
		substr[i++] = s[position++];
	substr[i] = '\0';
	return (substr);
}
