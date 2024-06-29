#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
#include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH 1200
# define HEIGHT 1200
//colors
#define WHITE 0xFFFFFF
#define BLACK 0x000000
#define RED   0xFF0000
#define GREEN 0x00FF00
#define BLUE  0x0000FF
#define AMARILLO_CLARO 0xFFFF66
#define AMARILLO_MEDIO 0xFFFF99
#define AMARILLO_OSCURO 0xFFFFCC
#define AZUL_CLARO 0x66FFFF
#define AZUL_MEDIO 0x99FFFF
#define AZUL_OSCURO 0xCCFFFF
//teclas
#define ESC 65307
//agus
#define C 99

typedef struct s_com
{
	double real;
	double img;
} t_com;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_fractal
{
	void *mlx;
	void *mlx_win;
	char name[11];
	t_img	img;
	int  quality;
	int zoom;
	int color;
	int *colores;

}t_fractal;

void fractal_init(t_fractal *fractal);
void m_error(void);
void color_change(t_fractal *fractal);
void render_fractal(t_fractal *fractal);
//math
double mapping(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_com complex_sum(t_com n1 , t_com n2);
t_com complex_square(t_com n);
//events
int close_app(t_fractal *fractal);
int key_handler(int keycode, t_fractal *fractal);


#endif