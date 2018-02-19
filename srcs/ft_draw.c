/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:44:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 20:24:17 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void point(double x, double y, void *mlx)
{
	double i;
	double j;

	i = x - 5;
	while (i < x + 5)
	{
		j = y - 5;
		while (j < y + 5)
		{
			i = ft_round(i);
			j = ft_round(j);
			mlx_pixel_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win, i, j, 0xFFFFFF);
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
	p1 = ft_newpoint(450,440);
	p2 = ft_newpoint(0,0);
	ft_draw_line(p1, p2, mlx);
	point(p1.x,p1.y, mlx);
//	ft_draw_line(p3, p2, mlx);
//	ft_draw_line(p1, p3, mlx);
	return (1);
}
