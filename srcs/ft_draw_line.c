/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_eq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 21:46:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void point(double x, double y, void *mlx, int color);

void ft_draw_line(t_point p1, t_point p2, void *mlx)
{
    double	pendant;
	t_point	tmp;
    double	x;
	double	y;

	if (p1.x < p2.x)
	{
		tmp = ft_newpoint(p1.x, p1.y);
		p1 = ft_newpoint(p2.x, p2.y);
		p2 = ft_newpoint(tmp.x, tmp.y);
	}
	x = p2.x;
    pendant =  (p1.y - p2.y) / (p1.x - p2.x);
	while (x < p1.x)
	{
		y = (p2.y + pendant * (x - p2.x));
//	mlx_pixel_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win, x, y, 0xFFFFFF);
		point(x, y, mlx, 0xFFFFFF);
		x++;
	}
	return ;
}
