
#include "../inc/fractol.h"


// dos posibles promps
// fractol mandelbrot
// fractol julia <real> <i>


int main (int arc, char **argv)
{ 
	(void)arc;
	(void)argv;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	(void)mlx_win;
	return (0);
}