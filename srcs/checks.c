/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:56:31 by framador          #+#    #+#             */
/*   Updated: 2024/06/23 16:05:14 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_validfd(char *str, t_data *img)
{
	int		fd;
	char	*line;
	size_t	len;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0 * write(2, "ERROR\nInvalid fd\n", 17));
	line = ft_get_next_line(fd);
	len = ft_strlen(line);
	while (line)
	{
		if (len != ft_strlen(line))
		{
			free(line);
			return (0 * write(2, "ERROR\nNot a rectangle\n", 22));
		}
		img->lines++;
		free(line);
		line = ft_get_next_line(fd);
	}
	img->rows = len;
	close(fd);
	return (len);
}

int	ft_mapcheck(t_data *img)
{
	int		i;
	int		j;
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
			{
				return (0 * write(2, "ERROR\nInvalid character\n", 24));
			}
		}
		i++;
	}
	return (1);
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
		{
			return (0 * write(2, "ERROR\nNot closed\n", 17));
		}
		y++;
	}
	x = img->lines - 1;
	y = 0;
	while (y < img->rows)
	{
		if (img->map[x][y] != '1')
		{
			return (0 * write(2, "ERROR\nNot closed\n", 17));
		}
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
		{
			return (0 * write(2, "ERROR\nNot closed\n", 17));
		}
		x++;
	}
	y = img->rows - 1;
	x = 0;
	while (x < img->lines)
	{
		if (img->map[x][y] != '1')
		{
			return (0 * write(2, "ERROR\nNot closed\n", 17));
		}
		x++;
	}
	return (1);
}

int	ft_checker(t_data *img, char *str)
{
	if (!ft_allocmap(str, img))
		return (0);
	if (!ft_mapcheck(img))
		return (0);
	if (!(img->player == 1 && img->exit == 1 && img->collect > 0))
		return (0 * write(2, "ERROR\nWrong exit player or collect\n", 35));
	if (!ft_checktopwalls(img) || !ft_checksidewalls(img))
		return (0);
	if (!ft_countcollect(img))
		return (0);
	return (1);
}
