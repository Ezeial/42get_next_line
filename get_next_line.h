#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 2

void	*ft_bzero(void *s, size_t n);
size_t	ft_strlcat(char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);

int		get_next_line(int fd, char **line);

#endif