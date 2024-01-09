/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:54:50 by youchen           #+#    #+#             */
/*   Updated: 2024/01/09 08:12:09 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_Complex z, double real, double imag)
{
	double	a;
	double	b;
	double	x;
	double	y;

	z.iter = 0;
	while (z.iter < MAX_ITER)
	{
		a = z.real * z.real;
		b = z.real * z.imag;
		x = z.imag * z.real;
		y = z.imag * z.imag;
		z.real = a - y + real;
		z.imag = b + x + imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (z.iter * 5);
		z.iter++;
	}
	return (z.iter);
}

int	mandelbrot(t_Complex c)
{
	t_Complex	z;
	double		a;
	double		b;
	double		x;
	double		y;

	z.real = 0;
	z.imag = 0;
	z.iter = 0;
	while (z.iter < MAX_ITER)
	{
		a = z.real * z.real;
		b = z.real * z.imag;
		x = z.imag * z.real;
		y = z.imag * z.imag;
		z.real = a - y + c.real;
		z.imag = b + x + c.imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (z.iter * 5);
		z.iter++;
	}
	return (z.iter);
}

int	draw(t_data *data, int x, int y)
{
	t_Complex	c;

	c.imag = data->max_imag - y * (data->max_imag - data->min_imag)
		/ (double)WIDTH;
	c.real = data->min_real + x * (data->max_real - data->min_real)
		/ (double)HEIGHT;
	if (ft_strcmp(data->fractal, "mandelbrot"))
		return (mandelbrot(c));
	else if (ft_strcmp(data->fractal, "julia"))
		return (julia(c, ft_atoi(data->argv[2]), ft_atoi(data->argv[3])));
	return (0);
}

void	draw_fractal(t_data *data, int width, int height)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			color = draw(data, x, y);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	error_handlling(argc, argv);
	data.argv = argv;
	data.fractal = argv[1];
	data.min_real = -2.0;
	data.max_real = 2.0;
	data.min_imag = -2.0;
	data.max_imag = 2.0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	draw_fractal(&data, WIDTH, HEIGHT);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 0, esc_close, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
