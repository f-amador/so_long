#include "../include/so_long.h"

int	ft_validfd(char *str, t_data *img)
{
	int	fd;
	char	*line;
	size_t	len;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	line = ft_get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		if (len != ft_strlen(line))
			return (0);
		img->lines++;
		free(line);
		line = ft_get_next_line(fd);
	}
	img->rows = len - 1;
	close(fd);
	return (len);
}


int ft_mapcheck(t_data *img)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (i < img->lines)
	{
		j = 0;
		while (j < img->rows)
		{
			c = img->map[i][j++];
			if (c == 'C')
				img->collect++;
			else if (c == 'P')
				img->player++;
			else if (c == 'E')
				img->exit++;
			else if (c != '0' && c != '1')
				return (0);
		}
		i++;
	}
	return ((img->player == 1 && img->exit == 1 && img->collect > 0));
}
int	ft_checktopwalls(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < img->rows)
	{
		if (img->map[x][y] != '1')
			return (0);
		y++;
	}
	x = img->lines - 1;
	y = 0;
	while (y < img->rows)
	{
		if (img->map[x][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	ft_checksidewalls(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < img->lines)
	{
		if (img->map[x][y] != '1')
			return (0);
		x++;
	}
	y = img->rows - 1;
	x = 0;
	while (x < img->lines)
	{
		if (img->map[x][y] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_checker(t_data *img, char *str)
{
	return (ft_allocmap(str, img) && ft_mapcheck(img)
		&& ft_countcollect(img) && ft_checktopwalls(img)
		&& ft_checksidewalls(img));
}
