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


int	paint_something(t_mlx *mlx);
int	close_window(t_mlx *mlx);

#endif