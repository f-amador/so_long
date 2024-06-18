
#include "../include/so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i])
	{
		if (s[i] == 10)
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	j;
	size_t	i;

	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && j < ft_strlen(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	if (s1)
		free(s1);
	return (str);
}

static void	ft_buffflusher(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && buff[i] != 10)
		i++;
	if (buff[i] == 10 && i < BUFFER_SIZE)
		i++;
	while (i < BUFFER_SIZE)
	{
		buff[j] = buff[i];
		buff[i] = 0;
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
		buff[j++] = 0;
}

char	*ft_get_next_line(int fd)
{
	char		*str;
	static char	buff[BUFFER_SIZE + 1];

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (BUFFER_SIZE > 0)
		{
			ft_buffflusher(buff);
			return (NULL);
		}
	}
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buff);
		ft_buffflusher(buff);
		if (str[ft_strlen(str) - 1] == 10)
			break ;
	}
	return (str);
}
