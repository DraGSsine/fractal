/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchen <youchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:21:57 by youchen           #+#    #+#             */
/*   Updated: 2024/01/09 13:46:54 by youchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atoi(const char *nptr)
{
	int		i;
	double	sign;
	double	result;
	double	scale;

	i = 0;
	sign = 1;
	result = 0;
	scale = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10.0 + nptr[i++] - '0';
	if (nptr[i++] == '.')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			scale /= 10;
			result += (nptr[i++] - '0') * scale;
		}
	}
	return (result * sign);
}

int	cheak_for_point(char *s)
{
	int	i;
	int	points;

	points = 0;
	i = 0;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1] == '.')
		return (0);
	while (s[i])
		if (s[i++] == '.')
			points++;
	if (points > 1 || s[i - 1] == '.' || s[0] == '.')
		return (0);
	return (1);
}

int	check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (cheak_for_point(s) == 0)
		return (0);
	while (s[i])
	{
		if (((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	error_handlling(int argc, char **argv)
{
	if (
		(argc > 4 || argc == 1)
		|| (ft_strcmp(argv[1], "julia")
			&& !(check(argv[2]) && check(argv[3])))
		|| (ft_strcmp(argv[1], "mandelbrot") && argc != 2)
		|| (ft_strcmp(argv[1], "julia") && argc != 4)
		|| !(ft_strcmp(argv[1], "julia") || ft_strcmp(argv[1], "mandelbrot")))
	{
		perror("Usage: ./fractol mandelbrot\n       ./fractol julia 0.4 0.4\n");
		exit(1);
	}
}
