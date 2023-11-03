#ifndef COLOR_STUDIES_H
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <string.h>
# define COLOR_STUDIES_H
# define HEIGHT 480
# define WIDTH 640

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void		*init;
	void		*window;
}	t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_pixel
{
	t_mlx	*mlx;
	int		line_color;
	t_data	*img;
}	t_pixel;


int	paint_something(t_mlx *mlx);
int	close_window(t_mlx *mlx);
int	put_pixel(t_mlx *mlx, int x, int y, int trgb, t_data *img);
int	bresenham(t_point point1, t_point point2, t_pixel *data);

#endif