
#include "../inc/fractol.h"


// dos posibles promps
// fractol mandelbrot
// fractol julia <real> <i>
size_t	ftstrlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return ((size_t)ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return ((size_t)ft_strlen(src));
}


int main (int arc, char **argv)
{ 
	t_fractal fractal;

	if ((arc == 2 && !ft_strncmp("mandelbrot",argv[1],11)) || 
		(arc == 4 && !ft_strncmp("julia",argv[1],6)))
	{
		ft_strlcpy(fractal.name,argv[1],11);
		fractal_init(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		ft_putstr_fd("Error de parametros /n",2);
	return (0);
}