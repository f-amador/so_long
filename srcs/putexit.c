#include "../include/so_long.h"

void	ft_putexit(t_data *img, int i, int j)
{
	if (img->start[0] == i && img->start[1] == j)
	{
		if (img->left)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->e3addr,
				j * 50, i * 50);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->e2addr,
				j * 50, i * 50);
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->eaddr,
			j * 50, i * 50);
}
