
#ifndef SO_LONG_H
# define SO_LONG_H

// --------BUFFER_SIZE-------
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// --------KEY_PRESS---------
# define ESC 65307

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
	char		*addr;
	int		bits_per_pixel;
	int		endian;
	int		lines;
	int		**map;
	int		rows;
	int		start[2];
	int		player;
	int		exit;
	int		exitc;
	int		collect;
}	t_data;

// --------PROTOTYPES--------
char	*ft_get_next_line(int fd);
size_t	ft_strlen(char const *s);
void	ft_win_destroy(t_data *img);
int 	ft_floodfill(t_data *img, int x, int y, int *collect);
int	ft_countcollect(t_data *img);



#endif
