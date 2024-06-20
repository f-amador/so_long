#include "../include/so_long.h"

static void ft_moveu(t_data *img)
{
	int	x;
	int	y;

	x = img->start[0];
	y = img->start[1];
	if (img->map[x - 1][y] != '1')
	{
		if (img->map[x - 1][y] == 'C')
			img->collectc++;
		img->start[0]--;
		if (img->map[x][y] != 'E')
            img->map[x][y] = '0';
        if (img->map[x - 1][y] != 'E')
            img->map[x - 1][y] = 'P';
		if (img->map[x - 1][y] == 'E' && img->collect == img ->collectc)
			ft_win_destroy(img);
		img->steps++;
		ft_drawimg(img); 
	}
}
static void ft_moved(t_data *img)
{
	int	x;
	int	y;

	x = img->start[0];
	y = img->start[1];
	if (img->map[x + 1][y] != '1')
	{
		if (img->map[x + 1][y] == 'C')
			img->collectc++;
		img->start[0]++;
		if (img->map[x][y] != 'E')
            img->map[x][y] = '0';
        if (img->map[x + 1][y] != 'E')
            img->map[x + 1][y] = 'P';
		if (img->map[x + 1][y] == 'E' && img->collect == img ->collectc)
			ft_win_destroy(img);
		img->steps++;
		ft_drawimg(img); 
	}
}
static void ft_movel(t_data *img)
{
    int x;
    int y;

    x = img->start[0];
    y = img->start[1];
    if (img->map[x][y - 1] != '1')
    {
        if (img->map[x][y - 1] == 'C')
            img->collectc++;
        img->start[1]--;
        if (img->map[x][y] != 'E')
            img->map[x][y] = '0';
        if (img->map[x][y - 1] != 'E')
            img->map[x][y - 1] = 'P';
		if (img->map[x][y - 1] == 'E' && img->collect == img ->collectc)
			ft_win_destroy(img);
		img->steps++;
        ft_drawimg(img); 
    }
}

static void ft_mover(t_data *img)
{
	int	x;
	int	y;

	x = img->start[0];
	y = img->start[1];
	if (img->map[x][y + 1] != '1')
	{
		if (img->map[x][y + 1] == 'C')
			img->collectc++;
		img->start[1]++;
		if (img->map[x][y] != 'E')
            img->map[x][y] = '0';
        if (img->map[x][y + 1] != 'E')
            img->map[x][y + 1] = 'P';
		if (img->map[x][y + 1] == 'E' && img->collect == img ->collectc)
			ft_win_destroy(img);
		img->steps++;
		ft_drawimg(img); 
	}
}
int	ft_keyhook(int keycode, t_data *img)
{
	write(1, "Moves:", 6);
	ft_putnbr(img->steps);
	write(1, "\n", 1);
	if (keycode == ESC)
		ft_win_destroy(img);
	else if (keycode == W_KEY || keycode == UP_KEY)
		ft_moveu(img);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		ft_moved(img);
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		ft_movel(img);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		ft_mover(img);
	return (0);
}