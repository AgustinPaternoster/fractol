#include "../inc/fractol.h"

void m_error(void)
{
    ft_putstr_fd("Malloc error\n",2);
    exit(EXIT_FAILURE);
}

t_com complex_sum(t_com n1 , t_com n2)
{
    t_com result;

    result.real = n1.real + n2.real;
    result.img = n1.img + n2.img;

    return (result);
}

t_com complex_square(t_com n)
{
    double tmp;
    t_com result;

    tmp = (n.real * n.real)- (n.img * n.img);
	result.img = 2 * n.real * n.img;
	result.real = tmp;

    return (result);
}

double mapping(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void color_change(t_fractal *fractal)
{
	static int count;
	
	if (count > 8 )
		count = 0;
	fractal->color = fractal->colores[count];
	count++;

}
