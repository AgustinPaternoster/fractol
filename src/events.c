#include "../inc/fractol.h"

int closeapp(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx,fractal->img.img);
	mlx_destroy_window(fractal->mlx , fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

// int closeapp(int keynote,t_fractal *fractal)
// {
// 	(void)keynote;
// 	mlx_destroy_image(fractal->mlx,fractal->img.img);
// 	mlx_destroy_window(fractal->mlx , fractal->mlx_win);
// 	mlx_destroy_display(fractal->mlx);
// 	exit(EXIT_SUCCESS);
// 	return (0);
// }