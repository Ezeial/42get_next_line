#include "get_next_line.h"

static int	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void *ft_bzero(void *s, size_t n)
{
	unsigned int    i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = (unsigned char)'\0';
	return (s);
}

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i] && i < n)
		i++;
	j = i;
	while (s2[i - j] && i + 1 < n)
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (j < n)
		s1[i] = '\0'; 
	return (j + ft_strlen(s2));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined;
	unsigned int	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(len * sizeof(char));
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	ft_strlcat(joined, s1, len);
	ft_strlcat(joined, s2, len);
	return (joined);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		len;
	int i;
	len = ft_strlen(str);
	copy = (char*)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < len)
		copy[i] = str[i];
	copy[i] = '\0';
	return (copy);
}