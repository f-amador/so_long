/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putexit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:08:34 by framador          #+#    #+#             */
/*   Updated: 2024/06/23 16:08:52 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_initstart(t_data *img, int i, int j)
{
	img->start[0] = i;
	img->start[1] = j;
}
