/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isousa-s <isousa-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:01:16 by isousa-s          #+#    #+#             */
/*   Updated: 2025/01/28 19:32:17 by isousa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *pending_text)
{
	int		len;
	char	*tmp;

	if (!pending_text)
		pending_text = ft_calloc(1, 1);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	len = 1;
	while (len > 0)
	{
		len = read(fd, tmp, BUFFER_SIZE);
		if (len == -1)
		{
			free(tmp);
			free(pending_text);
			return (NULL);
		}
		tmp[len] = '\0';
		pending_text = ft_free_strjoin(pending_text, tmp);
		if (ft_strchr(pending_text, '\n'))
			break ;
	}
	free(tmp);
	return (pending_text);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pending_text;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	pending_text = read_line(fd, pending_text);
	if (pending_text == NULL)
		return (NULL);
	line = get_line(pending_text);
	pending_text = cut_line(pending_text);
	return (line);
}

/*read_until_enter  - read_line
make_line_from - get_line
the_rest - cut_line 
save - pending_text
*/
