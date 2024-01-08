/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:56:20 by youchen           #+#    #+#             */
/*   Updated: 2024/01/08 10:29:04 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITER 1000
# define WIDTH 1000
# define HEIGHT 1000
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_Complex
{
	double	real;
	double	imag;
	double	a;
	double	b;
	double	x;
	double	y;
	int		iter;
}	t_Complex;


typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
	char	*fractal;
	char	**argv;
	int		width;
	int		height;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(void *param);
int		mouse_hook(int button, void *param);
void	draw_fractal(t_data *data, int width, int height);
double	ft_atoi(const char *nptr);
int		esc_close(int keycode, void *param);
int		ft_strcmp(const char *s1, const char *s2);
void	error_handlling(int argc, char **argv);
#endif
