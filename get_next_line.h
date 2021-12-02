#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(char const *str);
char	*ft_strnjoin(char *s1, char *s2, size_t n);
char	*get_next_line(int fd);

#endif