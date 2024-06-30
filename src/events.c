#include "../inc/fractol.h"

static void ft_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx,fractal->img.img);
	mlx_destroy_window(fractal->mlx , fractal->mlx_win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal->colores);
	exit(EXIT_SUCCESS);	
}

int close_app(t_fractal *fractal)
{
	ft_close (fractal);
	return (0);
}

static void move_screen(int keysym, t_fractal *fractal)
{
	if(keysym == XK_Right)
		fractal->move_x += 0.5 * fractal->zoom;
	if(keysym == XK_Left)
		fractal->move_x -= 0.5* fractal->zoom;
	if(keysym == XK_Up)
		fractal->move_y += 0.5 * fractal->zoom;
	if(keysym == XK_Down)
		fractal->move_y -= 0.5 * fractal->zoom;
}

int key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_app(fractal);
	if (keysym == XK_c)
		color_change(fractal);
	if (keysym == XK_plus)
		fractal->quality += 10;
	if (keysym == XK_minus)
		fractal->quality -= 10;
	if (keysym == XK_Left || keysym == XK_Right || keysym == XK_Up || keysym == XK_Down)
		move_screen(keysym,fractal);
	if (keysym == XK_r)
		fractal_data(fractal);
	render_fractal(fractal);
	

 	
	return (0);

}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if(button == 4)
		fractal->zoom *= 0.90;
	if(button == 5)
		fractal->zoom *= 1.10;
	(void)x;
	(void)y;
	(void)fractal;
	//ft_printf("%d", button);
	render_fractal(fractal);
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