/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framador <framador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:08:34 by framador          #+#    #+#             */
/*   Updated: 2025/05/31 13:39:47 by framador         ###   ########.fr       */
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
    void        *img;       // Main image buffer
    void        *mlx;       // MiniLibX instance
    void        *mlx_win;   // Window instance
    // Texture addresses
    void        *p2addr;
    void        *caddr;
    void        *eaddr;
    void        *e2addr;
    void        *e3addr;
    void        *paddr;
    void        *waddr;
    void        *faddr;
    char        *addr;      // Image data address
    int         steps;      // Move counter
    int         bimg;       // Bits per pixel
    int         lines;      // Map line count
    int         lines2;     // Secondary line count
    int         **map2;     // Secondary map array
    int         **map;      // Primary map array
    int         rows;       // Map row count
    int         start[2];   // Player start position
    int         player;     // Player count
    int         exit;       // Exit count
    int         exitc;      // Exit counter
    int         collect;    // Collectible count
    int         collectc;   // Collected items count
    int         left;       // Items remaining
} t_data;

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
