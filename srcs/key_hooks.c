/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:00:08 by framador          #+#    #+#             */
/*   Updated: 2024/06/22 17:01:17 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_moveu(t_data *img)
{
	int	x;
	int	y;

	x = img->start[0];
	y = img->start[1];
	if (img->map[x - 1][y] != '1')
	{
		img->steps++;
		if (img->map[x - 1][y] == 'C')
			img->collectc++;
		img->start[0]--;
		if (img->map[x][y] != 'E')
			img->map[x][y] = '0';
		if (img->map[x - 1][y] != 'E')
			img->map[x - 1][y] = 'P';
		if (img->map[x - 1][y] == 'E' && img->collect == img ->collectc)
		{
			ft_printmoves(img);
			ft_win_destroy(img);
		}
		ft_drawimg(img);
	}
	ft_printmoves(img);
}

static void	ft_moved(t_data *img)
{
	int	x;
	int	y;

	x = img->start[0];
	y = img->start[1];
	if (img->map[x + 1][y] != '1')
	{
		img->steps++;
		if (img->map[x + 1][y] == 'C')
			img->collectc++;
		img->start[0]++;
		if (img->map[x][y] != 'E')
			img->map[x][y] = '0';
		if (img->map[x + 1][y] != 'E')
			img->map[x + 1][y] = 'P';
		if (img->map[x + 1][y] == 'E' && img->collect == img ->collectc)
		{
			ft_printmoves(img);
			ft_win_destroy(img);
		}
		ft_drawimg(img);
	}
	ft_printmoves(img);
}

static void	ft_movel(t_data *img)
{
	int	x;
	int	y;

	x = img->start[0];
	y = img->start[1];
	if (img->map[x][y - 1] != '1')
	{
		img->steps++;
		if (img->map[x][y - 1] == 'C')
			img->collectc++;
		img->start[1]--;
		if (img->map[x][y] != 'E')
			img->map[x][y] = '0';
		if (img->map[x][y - 1] != 'E')
			img->map[x][y - 1] = 'P';
		if (img->map[x][y - 1] == 'E' && img->collect == img ->collectc)
		{
			ft_printmoves(img);
			ft_win_destroy(img);
		}
		img->left = 1;
		ft_drawimg(img);
	}
	ft_printmoves(img);
}

static void	ft_mover(t_data *img)
{
	int	x;
	int	y;

	x = img->start[0];
	y = img->start[1];
	if (img->map[x][y + 1] != '1')
	{
		img->steps++;
		if (img->map[x][y + 1] == 'C')
			img->collectc++;
		img->start[1]++;
		if (img->map[x][y] != 'E')
			img->map[x][y] = '0';
		if (img->map[x][y + 1] != 'E')
			img->map[x][y + 1] = 'P';
		if (img->map[x][y + 1] == 'E' && img->collect == img ->collectc)
		{
			ft_printmoves(img);
			ft_win_destroy(img);
		}
		img->left = 0;
		ft_drawimg(img);
	}
	ft_printmoves(img);
}

int	ft_keyhook(int keycode, t_data *img)
{
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
