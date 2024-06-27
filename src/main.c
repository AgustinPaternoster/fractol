
#include "../inc/fractol.h"


// dos posibles promps
// fractol mandelbrot
// fractol julia <real> <i>


int main (int arc, char **argv)
{ 
	(void)arc;
	(void)argv;
	if ((arc == 2 && !ft_strncmp("mandelbrot",argv[1],11)) || 
		(arc == 4 && !ft_strncmp("julia",argv[1],6)))
	{
		ft_printf("ok\n");
	}
	else
		ft_putstr_fd("Error de parametros /n",2);
	return (0);
}