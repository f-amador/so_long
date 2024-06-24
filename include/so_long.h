/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:08:34 by framador          #+#    #+#             */
/*   Updated: 2024/06/23 16:08:52 by framador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// --------BUFFER_SIZE-------
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// --------KEY_PRESS---------
# define ESC 65307
# define W_KEY 119
# define A_KEY	97
# define S_KEY	115
# define D_KEY	100
# define UP_KEY	65362
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define LEFT_KEY 65361

// --------CONSTANTS---------
# define INT_MAX 2147483647
# define INT_MIN -2147483648

// --------INCLUDES----------
# include "./minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

// --------STRUCTS-----------
typedef struct s_data {
	void		*img;
	void		*mlx;
	void		*mlx_win;
	void		*p2addr;
	void		*caddr;
	void		*eaddr;
	void		*e2addr;
	void		*e3addr;
	void		*paddr;
	void		*waddr;
	void		*faddr;
	char		*addr;
	int			steps;
	int			bimg;
	int			lines;
	int			lines2;
	int			**map2;
	int			**map;
	int			rows;
	int			start[2];
	int			player;
	int			exit;
	int			exitc;
	int			collect;
	int			collectc;
	int			left;
}	t_data;

// --------PROTOTYPES--------
char	*ft_get_next_line(int fd);
size_t	ft_strlen(char const *s);
int		ft_win_destroy(t_data *img);
int		ft_countcollect(t_data *img);
int		ft_validfd(char *str, t_data *img);
int		ft_mapcheck(t_data *img);
int		ft_keyhook(int keycode, t_data *img);
int		ft_checktopwalls(t_data *img);
int		ft_checksidewalls(t_data *img);
int		ft_checker(t_data *img, char *str);
int		ft_allocmap(char *str, t_data *img);
void	ft_floodfill(t_data *img, int x, int y, int *collect);
void	ft_initstart(t_data *img, int i, int j);
void	ft_putexit(t_data *img, int i, int j);
void	ft_printmoves(t_data *img);
void	ft_mlxinit(t_data *img);
void	ft_freemap(t_data *img);
void	ft_drawimg(t_data *img);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif
