#include "../inc/fractol.h"

void fractal_data(t_fractal *fractal)
{
    free(fractal->colores);
    fractal->colores = malloc(sizeof(int)*10);
    if (!fractal->colores)
        m_error();
    fractal->colores[0] =  COL1;
    fractal->colores[1] = COL2;
    fractal->colores[2] = COL3;
    fractal->colores[3] = COL4;
    fractal->colores[4] = COL5;
    fractal->colores[5] = BLACK;
    fractal->colores[6] = RED;
    fractal->colores[7] = BLUE;
    fractal->colores[8] = GREEN;
    fractal->colores[9] = WHITE;
    fractal->quality = 42;
    fractal->zoom = 1;
    fractal->color = fractal->colores[1];
    fractal->move_x = 0.0;
    fractal->move_y = 0.0;
    fractal->zoom = 1.0;
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