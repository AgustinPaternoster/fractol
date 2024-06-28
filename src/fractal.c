#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// ////////////////////////////////////////////////////////////////

static void get_img_data(t_fractal *fractal)
{
    fractal->img.addr = mlx_get_data_addr(fractal->img.img,
                                         &fractal->img.bits_per_pixel,
                                        &fractal->img.line_length,
                                        &fractal->img.endian);
    
}

void fractal_init(t_fractal *fractal)       
{
    fractal->mlx = mlx_init();
    if (fractal->mlx == NULL)
        m_error();
    fractal->mlx_win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_win == NULL)
    {
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        m_error();
    }
    fractal->img.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (fractal->img.img == NULL)
    {
        mlx_destroy_window(fractal->mlx,fractal->mlx_win);
        mlx_destroy_display(fractal->mlx);
        free(fractal->mlx);
        m_error();
    }
    get_img_data(fractal);
    // for (int i = 0 ; i < 5 ; i++)
	// 	my_mlx_pixel_put(&fractal->img , i, 5, 0x00FF0000);
	// for (int i = 0 ; i < 5 ; i++)
	// 	my_mlx_pixel_put(&fractal->img, i, 10, 0x0000FF00);
    // mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img.img, 0, 0);
}