/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:01:16 by isousa-s          #+#    #+#             */
/*   Updated: 2025/02/01 20:18:48 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*read_to_storage(int fd, char *storage)
{
    char    *buffer;
    int     bytes_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    
    while ((!storage || !ft_strchr(storage, '\n')) && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(storage);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        
        if (bytes_read > 0)
        {
            storage = ft_strjoin(storage, buffer);
        }
        
        if (!storage)
        {
            free(buffer);
            return (NULL);
        }
    }
    free(buffer);
    return (storage);
}

static char	*extract_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;

	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
			line[i] = storage[i];
			i++;
	}
	line[i] = '\0';
	return (line);

}

static char *update_storage(char *storage)
{
	char	*new_storage;
	int		i;
	int		j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	i++;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	storage = read_to_storage(fd, storage);
	if(!storage)
		return (NULL);
	line = extract_line(storage);
	storage = update_storage(storage);
	return (line);
}
