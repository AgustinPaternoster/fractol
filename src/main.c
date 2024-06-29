#include "../inc/fractol.h"

// dos posibles promps
// fractol mandelbrot
// fractol julia <real> <i>
void hook_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win,17, 1L<<17, close_app ,fractal);
	mlx_key_hook(fractal->mlx_win, key_handler, fractal);

}

int main (int arc, char **argv)
{ 
	t_fractal fractal;

	if ((arc == 2 && !ft_strncmp("mandelbrot",argv[1],11)) || 
		(arc == 4 && !ft_strncmp("julia",argv[1],6)))
	{
		ft_strlcpy(fractal.name,argv[1],11);
		fractal_init(&fractal);
		hook_init(&fractal);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		ft_putstr_fd("Error de parametros /n",2);
	return (0);
}