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

void	ft_fillmap(t_data *img, int fd)
{
	int	i;
	char	*line;
	int	j;
	
	i = 0;
	while (i < img->lines)
	{
		line = ft_get_next_line(fd);
		img->map[i] = (int *)malloc(img->rows * sizeof(int));
		if (!(img->map[i]))
			return ;
		j = 0;
		while(line[j] && line[j] != '\n')
		{
			if (line[j] == 'P')
			{
				img->start[0] = i;
				img->start[1] = j;
			}
			img->map[i][j] = (int)line[j];
			j++;
		}
		i++;
		free(line);
	}
}

int	ft_allocmap(char *str, t_data *img)
{
	int	fd;

	fd = open(str, O_RDONLY);
	img->map = (int **)malloc(img->lines * sizeof(int *));
	if (!(img->map))
		return (0);
	ft_fillmap(img, fd);
	close(fd);
	return (1);
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

int	main(int ac, char *av[])
{
	static t_data img;
	int i;
	int j;
	
	if (ac == 2 && ft_validfd(av[1], &img) && ft_allocmap(av[1], &img) && ft_mapcheck(&img) && ft_countcollect(&img))
	{
		i = 0;
		while (i < img.lines)
		{
			j = 0;
			while (j < img.rows)
			{
				j++;
			}
			free(img.map[i]);
			i++;
		}
		free(img.map);
	}
	else
		return (write(2, "ERROR\n", 6));

}
