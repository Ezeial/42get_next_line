#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>


int ft_find_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char *ft_make_newline(char *line, char *buffer)
{
	char *newline;

	newline = ft_strjoin(line, buffer);
	free(line);
	return (newline);
}

char *ft_str_get_remain(char buffer[BUFFER_SIZE + 1])
{
	char *remain;
	size_t i;
	size_t j;

	i = 0;
	while (buffer[i] != '\n' && i < (BUFFER_SIZE))
		i++;
	i++;
	j = 0;
	while (buffer[i + j] && i + j < (BUFFER_SIZE))
		j++;
	remain = (char *)malloc(sizeof(char) * (j + 1));
	if (!remain)
		return (NULL);
	ft_strlcpy(remain, &buffer[i], j + 1);
	return (remain);
}

int get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static char *remain;
	char *temp;
	int index;
	int bytes_read;

	if (remain)
	{
		free(*line);
		*line = ft_strdup(remain);
	}
	while (bytes_read = read(fd, buffer, BUFFER_SIZE))
	{
		if (bytes_read < 0)
			return (-1);
		if (-1 < index)
		{
			free(remain);
			remain = ft_str_get_remain(buffer);

			buffer[index] = '\0';
			break ;
		}
		*line = ft_make_newline(*line, buffer);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	*line = ft_make_newline(*line, buffer);
	return (0);
}