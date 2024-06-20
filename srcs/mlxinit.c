#include "../include/so_long.h"



void	ft_loadimg(t_data *img)
{
    img->bimg = 50;
    img->caddress = mlx_xpm_file_to_image(img->mlx, "./sprites/collective.xpm", &(img->bimg), &(img->bimg));
    img->eaddress = mlx_xpm_file_to_image(img->mlx, "./sprites/exit.xpm", &(img->bimg), &(img->bimg));
    img->faddress = mlx_xpm_file_to_image(img->mlx, "./sprites/floor.xpm", &(img->bimg), &(img->bimg));
    img->paddress = mlx_xpm_file_to_image(img->mlx, "./sprites/player.xpm", &(img->bimg), &(img->bimg));
    img->waddress = mlx_xpm_file_to_image(img->mlx, "./sprites/wall.xpm", &(img->bimg), &(img->bimg));

}
void	ft_drawimg(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->lines)
	{
		j = 0;
		while (j < img->rows)
		{
			if (img->map[i][j] == '1')
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->waddress, j * 50, i * 50);
			else if (img->map[i][j] == '0')
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->faddress, j * 50, i * 50);
			else if (img->map[i][j] == 'P')
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->paddress, j * 50, i * 50);
			else if (img->map[i][j] == 'C')
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->caddress, j * 50, i * 50);
			else
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->eaddress, j * 50, i * 50);
			j++;
		}
		i++;
	}
}


int	ft_win_destroy(t_data *img)
{
	mlx_destroy_image(img->mlx, img->caddress);
    mlx_destroy_image(img->mlx, img->waddress);
    mlx_destroy_image(img->mlx, img->faddress);
    mlx_destroy_image(img->mlx, img->eaddress);
    mlx_destroy_image(img->mlx, img->paddress);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	mlx_loop_end(img->mlx);
	free(img->mlx);
	ft_freemap(img);
	exit(1);
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


void	ft_mlxinit(t_data *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->rows * 50, img->lines * 50, "so_long");
	ft_loadimg(img);
	ft_drawimg(img);
	mlx_key_hook(img->mlx_win, ft_keyhook, img);
	mlx_hook(img->mlx_win, 17, 0, ft_win_destroy, img);
	mlx_loop(img->mlx);
}
