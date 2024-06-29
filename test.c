#include <math.h>
#include <stdio.h>

#define AMARILLO_CLARO 0xFFFF66
#define AMARILLO_MEDIO 0xFFFF99
#define AMARILLO_OSCURO 0xFFFFCC
#define AZUL_CLARO 0x66FFFF
#define AZUL_MEDIO 0x99FFFF
#define AZUL_OSCURO 0xCCFFFF

/// test funcion cambio de color
typedef struct s_fractal
{
	void *mlx;
	void *mlx_win;
	char name[11];
	//t_img	img;
	int  quality;
	int zoom;
	int color;
	int *colores;

}t_fractal;

void init_col(t_fractal *fractal)
{
	fractal->colores[0] =  AZUL_OSCURO;
	fractal->colores[1] = AZUL_MEDIO;
	fractal->colores[2] = AZUL_CLARO;
	fractal->colores[3] = AMARILLO_CLARO;
	fractal->colores[4] = AMARILLO_MEDIO;
	fractal->colores[5] = AMARILLO_OSCURO;
	fractal->color = fractal->colores[0];
}

void color_change(t_fractal *fractal)
{
	static int count;
	
	if (count > 5 )
		count = 0;
	fractal->color = fractal->colores[count];
	count++;

}



int main(void)
{
	t_com z;
	t_com c;
	double tmp;

	z.real = 0;
	z.img = 0;

	c.real = 5;
	c.img = 2;
	next_number(c ,z , 2);
	return (0);
}