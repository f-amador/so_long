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

int	**ft_dupmap(t_data *img, int lines, int rows)
{
	int	j;
	int	i;
	int	**visited;

	i = 0;
	visited = malloc(lines * sizeof(int *));
	if (!visited)
		return (NULL);
	while (i < lines)
	{
		j = 0;
		visited[i] = malloc(rows * sizeof(int));
		if (!visited[i])
			break ;
		while (j < rows)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	img->lines2 = i;
	return (visited);
}

int	ft_countcollect(t_data *img)
{
	int	collect;
	int	i;

	i = 0;
	collect = 0;
	img->map2 = ft_dupmap(img, img->lines, img->rows);
	if (img->lines2 == img->lines)
		ft_floodfill(img, img->start[0], img->start[1], &collect);
	while (i < img->lines2)
		free(img->map2[i++]);
	free(img->map2);
	if (img->exitc && img->collect == collect && img->lines == img->lines2)
		return (1);
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
	img->exitc += (img->map[x][y] == 'E');
	(*collect) += (img->map[x][y] == 'C');
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
