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

	z.real = mapping(x,-2.00,2.00,0,WIDTH) * fractal->zoom + fractal->move_x ;
	z.img = mapping(y, 2.00,-2.00,0,HEIGHT) * fractal->zoom + fractal->move_y;
	c.real = fractal->julia_real;
	c.img =  fractal->julia_img;

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

void render_fractal_j(t_fractal *fractal)
{

	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			draw_pixel(x,y,fractal);
			x++;
		}
		y++;
	}	
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,fractal->img.img, 0, 0);
	return ;
}