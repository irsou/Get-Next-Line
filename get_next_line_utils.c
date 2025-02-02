/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:03:26 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/02 10:33:27 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		pos;

	if (s == NULL)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] == (char)c)
			return ((char *)&s[pos]);
		pos++;
	}
	if ((char)c == '\0')
		return ((char *)&s[pos]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t		position;

	position = 0;
	while (str[position] != '\0')
		position ++;
	return (position);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}
