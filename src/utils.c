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

void next_number(t_com c, t_com z, int interac)
{
	// z = z2 + c;
	// square :(x2 - y2) + 2xyi
	int i;

	i = 0;
	while (i < interac)
	{
		z = complex_sum(complex_square(z),c);
        i++;
	}
}