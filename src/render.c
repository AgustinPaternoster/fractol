#include "../inc/fractol.h"


static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



static void draw_pixel(int x, int y , t_fractal *fractal)
{
	t_com z;
	t_com c;
	int i;
	int color;
	
	z.real = 0.0;
	z.img = 0.0;
	c.real = mapping(x,-2.00,2.00,0,WIDTH) * fractal->zoom + fractal->move_x ;
	c.img = mapping(y, 2.00,-2.00,0,HEIGHT) * fractal->zoom + fractal->move_y;

	i = 0;
	while(i < fractal->quality)
	{
		z = complex_sum(complex_square(z),c);
		if ((z.real * z.real) + (z.img * z.img) > 4)
		{
			color = mapping(i,BLACK,WHITE,0 , fractal->quality);
			my_mlx_pixel_put(&fractal->img,x , y, color);
			return ;
		}
		i++;
	} 
	my_mlx_pixel_put(&fractal->img,x,y,fractal->color);
}

static void draw_pixel_j(int x, int y , t_fractal *fractal)
{
	t_com z;
	t_com c;
	int i;
	int color;
	
	z.real = 0.0;
	z.img = 0.0;
	c.real = mapping(x,-2.00,2.00,0,WIDTH) * fractal->zoom + fractal->move_x ;
	c.img = mapping(y, 2.00,-2.00,0,HEIGHT) * fractal->zoom + fractal->move_y;

	i = 0;
	while(i < fractal->quality)
	{
		z = complex_sum(complex_square(z),c);
		if ((z.real * z.real) + (z.img * z.img) > 4)
		{
			color = mapping(i,BLACK,WHITE,0 , fractal->quality);
			my_mlx_pixel_put(&fractal->img,x , y, color);
			return ;
		}
		i++;
	} 
	my_mlx_pixel_put(&fractal->img,x,y,fractal->color);
}

void render_fractal(t_fractal *fractal)
{
	int x;
	int y;

	y = -1;
	if (!ft_strncmp("mandelbrot",fractal->name,11))
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while(++x < WIDTH)
				draw_pixel(x,y,fractal);
		}
	}
	else
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while(++x < WIDTH)
				draw_pixel_j(x,y,fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,fractal->img.img, 0, 0);
	return ;
}