#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>


static int	ft_find_index(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	read_till_newline(int fd, char **remain)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;
	int		ret;

	bytes_read = 0;
	while (1)
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (ret);
		bytes_read += ret;
		if (*remain)
		{
			temp = ft_strjoin(*remain, buffer);
			free(*remain);
			*remain = temp;
		}
		else
			*remain = ft_strdup(buffer);
		if (-1 < ft_find_index(*remain, '\n'))
			return (bytes_read);
	}
}

static char *get_line(char *remain)
{
	char *line;
	int i;
	int newline_i;

	newline_i = ft_find_index(remain, '\n');
	line = malloc(sizeof(char) * (newline_i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < newline_i)
		line[i++] = remain[i];
	line[i] = '\0';
	return (line);
}

static void	remove_first_line_from_remain(char **remain)
{
	char *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	while ((*remain)[i] && (*remain)[i] != '\n')
		i++;
	i++;
	temp = ft_strdup((*remain) + i);
	free(*remain);
	*remain = temp;
}

int	get_next_line(int fd, char **line)
{
	static char *remain;
	int	read_ret;

	if (!remain || ft_find_index(remain, '\n') < 0)
	{
		read_ret = read_till_newline(fd, &remain);
		if (read_ret == -1)
			return (-1);
		if (read_ret == 0)
		{
			*line = ft_strdup(remain);
			return (0);
		}	
	}
	*line = get_line(remain);
	remove_first_line_from_remain(&remain);
	return (1);
}