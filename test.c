#include <math.h>
#include <stdio.h>

typedef struct s_com
{
	double real;
	double img;
} t_com;





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