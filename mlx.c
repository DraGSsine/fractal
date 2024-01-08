/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:54:45 by youchen           #+#    #+#             */
/*   Updated: 2024/01/08 10:35:15 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_window(void *param)
{
	t_data	*data;

	data = param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	esc_close(int keycode, void *param)
{
	if (keycode == 53)
		close_window(param);
	return (0);
}

int	mouse_hook(int button, void *param)
{
	t_data	*data;

	data = param;
	if (button == 5)
	{
		data->min_real *= 0.5;
		data->max_real *= 0.5;
		data->min_imag *= 0.5;
		data->max_imag *= 0.5;
	}
	else if (button == 4)
	{
		data->min_real /= 0.5;
		data->max_real /= 0.5;
		data->min_imag /= 0.5;
		data->max_imag /= 0.5;
	}
	// draw_fractal(param, WIDTH, HEIGHT);
	return (1);
}
