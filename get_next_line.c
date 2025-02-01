/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:01:16 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/01 09:55:12 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*line;
	int			bytes_read;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1 ));
	if(!buffer)
		return (NULL);

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read]= '\0';
	line=buffer;
	return (line);


	storage = NULL;
}
