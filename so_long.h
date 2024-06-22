
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
	void		*caddr;
	void		*eaddr;
	void		*paddr;
	void		*p2addr;
	void		*waddr;
	void		*faddr;
	char		*addr;
	int		steps;
	int		bimg;
	int		endian;
	int		lines;
	int		**map;
	int		rows;
	int		start[2];
	int		player;
	int		exit;
	int		exitc;
	int		collect;
	int		collectc;
}	t_data;

// --------PROTOTYPES--------
char	*ft_get_next_line(int fd);
size_t	ft_strlen(char const *s);
int	ft_win_destroy(t_data *img);
int 	ft_floodfill(t_data *img, int x, int y, int *collect);
int	ft_countcollect(t_data *img);
void	ft_mlxinit(t_data *img);
int	ft_keyhook(int keycode, t_data *img);
void	ft_freemap(t_data *img);
void	ft_putnbr(int n);
void	ft_drawimg(t_data *img);
void	ft_putchar(char c);
int	ft_validfd(char *str, t_data *img);
int ft_mapcheck(t_data *img);
int	ft_checktopwalls(t_data *img);
int	ft_checksidewalls(t_data *img);
int	ft_checker(t_data *img, char *str);
int	ft_allocmap(char *str, t_data *img);

#endif
