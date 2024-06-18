#include "../include/so_long.h"

int ft_floodFill(t_data *img, int x, int y) 
{
    int result;
    int tmp;

    if (x < 0 || x >= img->lines || y < 0 || y >= img->length)
        return 0;
    if (img->map[x][y] == '1')
        return 0;
    if (img->map[x][y] == 'C' || img->map[x][y] == 'E')
        return 1;
    tmp = img->map[x][y];
    img->map[x][y] = '1';
    result = ft_floodFill(img, x + 1, y) || ft_floodFill(img, x - 1, y) || ft_floodFill(img, x, y + 1) || ft_floodFill(img, x, y - 1);
    img->map[x][y] = tmp;
    return result;
}
