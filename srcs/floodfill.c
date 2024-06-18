#include "../include/so_long.h"

int	ft_countcollect(t_data *img)
{
	int	collect;
	int i = 0;
	int j;

	collect = 0;
	ft_floodfill(img, img->start[0], img->start[1], &collect);
	if ((collect == img->collect) && img->exitc)
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
	return (0);
}

int ft_floodfill(t_data *img, int x, int y, int *collect) 
{
	int result;
	char tmp;

	result = 0;
	if (x < 0 || x >= img->lines || y < 0 || y >= img->rows)
		return (0);
	tmp = img->map[x][y];
	if (tmp == '1' || tmp == 'V')
		return (0);
	if (tmp == 'E')
		img->exitc = 1;
	if (tmp == 'C')
	{
		(*collect)++;
		//img->map[x][y] = 'V';
	}
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
