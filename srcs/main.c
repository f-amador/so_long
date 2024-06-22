#include "../include/so_long.h"


void	ft_freemap(t_data *img)
{
	int i;
	int j;
		i = 0;
		while (i < img->lines)
		{
			j = 0;
			while (j < img->rows)
			{
				j++;
			}
			free(img->map[i]);
			i++;
		}
		free(img->map);
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

int	main(int ac, char *av[])
{
	static t_data	img;
	int				i;

	if (ac == 2 && ft_validfd(av[1], &img) && ft_checker(&img, av[1]))
	{
		i = ft_strlen(av[1]) - 1;
		if (i >= 3 && av[1][i] == 'r' && av[1][i - 1] == 'e'
				&& av[1][i - 2] == 'b' && av[1][i - 3] == '.')
			ft_mlxinit(&img);
	}
	else
		return (ft_freemap(&img), write(2, "ERROR\n", 6));
	ft_freemap(&img);
}
