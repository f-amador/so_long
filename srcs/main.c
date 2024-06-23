/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:54:05 by framador          #+#    #+#             */
/*   Updated: 2024/06/23 16:03:24 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_printmoves(t_data *img)
{
	write(1, "Moves:", 6);
	ft_putnbr(img->steps);
	write(1, "\n", 1);
}

void	ft_freemap(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->map && i < img->lines)
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
	int		i;
	char	*line;
	int		j;

	i = 0;
	while (i < img->lines)
	{
		line = ft_get_next_line(fd);
		img->map[i] = (int *)malloc(img->rows * sizeof(int));
		if (!(img->map[i]))
			return ((void)write(2, "ERROR\nMalloc Failed\n", 20));
		j = 0;
		while (j < img->rows)
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
		return (0 * write(2, "ERROR\nMalloc Failed\n", 20));
	ft_fillmap(img, fd);
	close(fd);
	return (1);
}

int	main(int ac, char *av[])
{
	static t_data	img;
	int				i;

	if (ac == 2)
	{
		if (ft_validfd(av[1], &img) && ft_checker(&img, av[1]))
		{
			i = ft_strlen(av[1]) - 1;
			if (i >= 3 && av[1][i] == 'r' && av[1][i - 1] == 'e'
					&& av[1][i - 2] == 'b' && av[1][i - 3] == '.')
				ft_mlxinit(&img);
		}
	}
	else
		return (write(2, "ERROR\nWrong number of args\n", 27));
	ft_freemap(&img);
}
