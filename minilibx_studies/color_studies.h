#ifndef COLOR_STUDIES_H
# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# define COLOR_STUDIES_H
# define HEIGHT 800
# define WIGTH 600


typedef struct s_mlx
{
	void		*init;
	void		*window;
}	t_mlx;


int	paint_something(t_mlx *mlx);
int	close_window(t_mlx *mlx);

#endif