#include "../include/so_long.h"



void	ft_loadimg(t_data *img)
{
    img->bimg = 50;
	img->p2addr = mlx_xpm_file_to_image(img->mlx, "./sprites/player2.xpm", &(img->bimg), &(img->bimg));
    img->caddr = mlx_xpm_file_to_image(img->mlx, "./sprites/collective.xpm", &(img->bimg), &(img->bimg));
    img->eaddr = mlx_xpm_file_to_image(img->mlx, "./sprites/exit.xpm", &(img->bimg), &(img->bimg));
    img->faddr = mlx_xpm_file_to_image(img->mlx, "./sprites/floor.xpm", &(img->bimg), &(img->bimg));
    img->paddr = mlx_xpm_file_to_image(img->mlx, "./sprites/player.xpm", &(img->bimg), &(img->bimg));
    img->waddr = mlx_xpm_file_to_image(img->mlx, "./sprites/wall.xpm", &(img->bimg), &(img->bimg));
	if (!img->caddr || !img->eaddr || !img->faddr || !img->paddr || !img->waddr)
		ft_win_destroy(img);
}
void	ft_putimg(t_data *img, int i, int j)
{
			if (img->map[i][j] == '1')
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->waddr, j * 50, i * 50);
			else if (img->map[i][j] == '0')
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->faddr, j * 50, i * 50);
			else if (img->map[i][j] == 'P')
			{
				if (img->left)
					mlx_put_image_to_window(img->mlx, img->mlx_win, img->p2addr, j * 50, i * 50);
				else
					mlx_put_image_to_window(img->mlx, img->mlx_win, img->paddr, j * 50, i * 50);
			}
			else if (img->map[i][j] == 'C')
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->caddr, j * 50, i * 50);
			else
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->eaddr, j * 50, i * 50);
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
			ft_putimg(img, i, j);
			j++;
		}
		i++;
	}
}


int	ft_win_destroy(t_data *img)
{
	if (img->caddr)
		mlx_destroy_image(img->mlx, img->caddr);
	if  (img->waddr)
    	mlx_destroy_image(img->mlx, img->waddr);
	if (img->faddr)
    	mlx_destroy_image(img->mlx, img->faddr);
	if (img->eaddr)
    	mlx_destroy_image(img->mlx, img->eaddr);
	if (img->paddr)
    	mlx_destroy_image(img->mlx, img->paddr);
	if (img->p2addr)
		mlx_destroy_image(img->mlx, img->p2addr);
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
