/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:58:22 by framador          #+#    #+#             */
/*   Updated: 2024/06/23 23:00:56 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s && s[i] && s[i] != 10)
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int **ft_dupmap(int lines, int rows)
{
	int	j;
	int	i;
	int **visited;
	
	visited = malloc(lines * sizeof(int *));
	while(i < lines) 
	{
		j = 0;
		visited[i] = malloc(rows * sizeof(int));
		while(j < rows) 
		{
			visited[i][j] = 0;
			j++;
		}
	}
	return visited;
}

void ft_checkflood(t_data *img, int *collect) 
{
	img->map2 = ft_dupmap(img->lines, img->rows);
	ft_floodfill(img, img->start[0], img->start[1], collect);
	for (int i = 0; i < img->lines; i++) {
		free(img->map2[i]);
	}
	free(img->map2);
}
int	ft_countcollect(t_data *img)
{
	int	collect;
	int	i;
	int	j;

	i = 0;
	collect = 0;
	ft_checkflood(img, &collect);
	if (img->exitc && img->collect == collect)
	{
		while (i < img->lines)
		{
			j = 0;
			while (j < img->rows)
			{
				if (img->map[i][j] == 'V')
					img->map[i][j] = 'C';
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0 * write(2, "ERROR\nFloodfill failed\n", 23));
}

void	ft_floodfill(t_data *img, int x, int y, int *collect)
{
	if (x < 0 || x >= img->lines || y < 0 || y >= img->rows || img->map2[x][y])
		return ;
	if (img->exitc && img->collect == *collect)
		return ;
	img->map2[x][y] = 1;
	if (img->map[x][y] == '1')
		return ;
	if (img->map[x][y] == 'E')
		img->exitc = 1;
	if (img->map[x][y] == 'C')
		(*collect)++;
	ft_floodfill(img, x + 1, y, collect);
	ft_floodfill(img, x - 1, y, collect);
	ft_floodfill(img, x, y + 1, collect);
	ft_floodfill(img, x, y - 1, collect);
	return ;
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}
