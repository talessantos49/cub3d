#include "color_studies.h"

int	key_input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		close_window(mlx);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->window);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit (0);
}

void	open_window(t_mlx *mlx)
{
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, WIDTH, HEIGHT, "minilibx studies");
	mlx_key_hook(mlx->window, &key_input, mlx);
	mlx_loop_hook(mlx->init, &paint_something, mlx);
	mlx_hook(mlx->window, 17, 0, &close_window, mlx); //x da janela
	mlx_loop(mlx->init);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	open_window(&mlx);
	return (0);
}
