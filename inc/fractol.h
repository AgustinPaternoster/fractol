#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
#include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800



typedef struct s_com
{
	int real;
	int img;
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

}t_fractal;

void fractal_init(t_fractal *fractal);

void m_error(void);



#endif