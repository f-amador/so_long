/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:58:22 by framador          #+#    #+#             */
/*   Updated: 2024/06/23 16:03:37 by framador         ###   ########.fr       */
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

int	ft_countcollect(t_data *img)
{
	int	collect;
	int	i;
	int	j;

	i = 0;
	collect = 0;
	if (ft_floodfill(img, img->start[0], img->start[1], &collect))
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

int	ft_floodfill(t_data *img, int x, int y, int *collect)
{
	int		result;
	char	tmp;

	result = 0;
	if (x < 0 || x >= img->lines || y < 0 || y >= img->rows)
		return (0);
	if (img->exitc && img->collect == *collect)
		return (1);
	tmp = img->map[x][y];
	if (tmp == '1' || tmp == 'V')
		return (0);
	if (tmp == 'E')
		img->exitc = 1;
	if (tmp == 'C')
		(*collect)++;
	if (tmp != 'E')
		img->map[x][y] = 'V';
	result = ft_floodfill(img, x + 1, y, collect)
		|| ft_floodfill(img, x - 1, y, collect)
		|| ft_floodfill(img, x, y + 1, collect)
		|| ft_floodfill(img, x, y - 1, collect);
	if (tmp != 'C')
		img->map[x][y] = tmp;
	return (result);
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
