#include "get_next_line.h"

static int		ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int		ft_find_index(char *str, char c)
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

static void 	ft_shift_buffer(char buffer[BUFFER_SIZE + 1], int n)
{
	size_t	i;

	i = 0;
	while (n > 0 && n + i < BUFFER_SIZE + 1)
	{
		buffer[i] = buffer[n + i];
		i++;
	}
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = 0;
		i++;
	}
}

static char 	*ft_join_buffer(char *line, char buffer[BUFFER_SIZE + 1], int n)
{
	int 	len;
	char 	*joined;
	int		i;

	if (n < 0)
		len = ft_strlen(buffer);
	else
		len = n + 1;
	if (line)
		len += ft_strlen(line);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (line && line[i])
		joined[i++] = line[i];
	while (i < len)
		joined[i++] = *buffer++;
	joined[i] = 0;
	return (joined); 
}

char			*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char 		*line;
	char		*temp;
	int			newline_idx;

	line = NULL;
	while (42)
	{
		newline_idx = ft_find_index(buffer, '\n');
		temp = line;
		line = ft_join_buffer(line, buffer, newline_idx);
		if (temp)
			free(temp);
		ft_shift_buffer(buffer, newline_idx + 1);
		if (0 <= newline_idx)
			return (line);
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
		{
			if (!ft_strlen(line))
			{
				free(line);
				return (NULL);
			}
			else
				return (line);
		}
	}
}