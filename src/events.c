#include "../inc/fractol.h"

static void ft_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx,fractal->img.img);
	mlx_destroy_window(fractal->mlx , fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);	
}

int close_app(t_fractal *fractal)
{
	ft_close (fractal);
	return (0);
}

int key_handler(int keysym, t_fractal *fractal)
{
	// (void)fractal;
	// ft_printf("%d",keysym);
	if (keysym == ESC)
		close_app(fractal);
	if (keysym == C)
		ft_printf("ok");
	ft_printf("%d",keysym);
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