#include "fractol.h"
#include <libc.h>
int mandelbrot(Complex c)
{
	Complex z = {0, 0};
	int iter = 0;

	while (iter < MAX_ITER)
	{
		double real_squared = z.real * z.real;
		double imag_squared = z.imag * z.imag;

		if (real_squared + imag_squared > 4)
			return iter * 20;

		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = real_squared - imag_squared + c.real;

		iter++;
	}

	return iter;
}
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int close_window(int keycode,t_data *data)
{
	(void)keycode;
	mlx_destroy_window(data->mlx,data->win);
	return(0);
}
void draw_mandelbrot(t_data *data, int width, int height)
{
	double min_real = -2.0;
	double max_real = 2.0;
	double min_imag = -2.0;
	double max_imag = 2.0;
	int x = 0;
	int y = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			Complex c =
			{
				min_real + x * (max_real - min_real) / (double)width,
				min_imag + y * (max_imag - min_imag) / (double)height
			};

			int iter = mandelbrot(c);
			int color = iter | iter << 8;
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

int main()
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx , 1000, 1000, "Mandelbrot Set");
	data.img = mlx_new_image(data.mlx , 1000, 1000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								 &data.endian);
	draw_mandelbrot(&data, 1000, 1000);
	mlx_put_image_to_window(data.mlx , data.win, data.img, 0, 0);
	mlx_hook(data.win,2, 1L<<0,close_window,&data);
	mlx_loop(data.mlx );

	return 0;
}
