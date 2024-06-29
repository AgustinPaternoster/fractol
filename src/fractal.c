#include "../inc/fractol.h"

static void fractal_data(t_fractal *fractal)
{
    fractal->quality = 42;
    fractal->zoom = 1;
	// fractal->colores[0] =  AZUL_OSCURO;
	// fractal->colores[1] = AZUL_MEDIO;
	// fractal->colores[2] = AZUL_CLARO;
	// fractal->colores[3] = AMARILLO_CLARO;
	// fractal->colores[4] = AMARILLO_MEDIO;
	// fractal->colores[5] = AMARILLO_OSCURO;
	// fractal->color = fractal->colores[0];
}


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
    fractal_data(fractal);
}