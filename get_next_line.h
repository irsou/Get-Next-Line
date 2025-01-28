#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

void	*ft_calloc(size_t num, size_t size);
char	*get_next_line(int fd);
char	*read_line(int fd, char *pending_text);

# endif