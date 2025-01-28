/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:03:26 by isousa-s          #+#    #+#             */
/*   Updated: 2025/01/28 19:33:41 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	*ft_memset(void *ptr, int value, size_t length)
{
	size_t			pos;
	unsigned char	*dir;

	pos = 0;
	dir = ptr;
	while (pos < length)
	{
		dir[pos] = (unsigned char)value;
		pos++;
	}
	return (dir);
}


void	ft_bzero(void *ptr, size_t len)
{
	ft_memset(ptr, 0, len);
}


void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, num * size);
	return (ptr);
}
