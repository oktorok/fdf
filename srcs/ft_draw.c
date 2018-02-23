/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:44:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 21:46:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void point(double x, double y, void *mlx, int color)
{
	double i;
	double j;

	i = x - 1;
/*	while (i < x + 1)
	{
		j = y - 1;
		while (j < y + 1)
		{
			mlx_pixel_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win, i, j, color);
			j++;
		}
		i++;
	}*/
	int r = 130;

	i = x - r;
	while (i < x + r)
	{
		j = y - r;
		while (j < y + r)
		{
			if (pow(i - x, 2) + pow(j - y, 2) == r)
				mlx_pixel_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win, i, j, color);
			j++;
		}
		i++;
	}
}

int	ft_draw(void *mlx, int code)
{
	t_point p1;
	t_point p2;
	t_point p3;

//	p3 = ft_newpoint(20,400);
	p1 = ft_newpoint(400,450);
	p2 = ft_newpoint(350,400);
	//ft_draw_line(p1, p2, mlx);
	point(p1.x,p1.y, mlx, 0xFFFFFF);
	point(p2.x,p2.y, mlx, 0xA1A1A1);
//	ft_draw_line(p3, p2, mlx);
//	ft_draw_line(p1, p3, mlx);
	return (1);
}
