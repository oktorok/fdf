/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/06 06:27:37 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void vertical_draw(t_point p[2], void *mlx, int height, int height2)
{
	double	pendant;
	int		cuant;
	int		num;

	pendant = ft_pendant(p[0], p[1]);
	cuant = labs(p[1].y - p[0].y) + 1;
	num = 1;
	if (p[0].y < p[1].y)
	{
		while (p[0].y < p[1].y)
		{
			p[0].x = ft_equline(p[1], pendant, p[0].y, '-');
			ft_point(ft_newpoint(p[0].x, -p[0].y++), mlx, ft_get_color(height,
				height2, cuant, num++));
		}
		return ;
	}
	while (p[0].y > p[1].y)
	{
		p[0].x = ft_equline(p[1], pendant, p[0].y, '-');
		ft_point(ft_newpoint(p[0].x, -p[0].y--), mlx, ft_get_color(height,
			height2, cuant, num++));
	}
}

static void	horizontal_draw(t_point p[2], void *mlx, int h, int h2)
{
	double	pendant;
	int		cuant;
	int		num;

	pendant = ft_pendant(p[0], p[1]);
	cuant = labs(p[0].x - p[1].x) + 1;
	num = 1;
	if (p[0].x < p[1].x)
	{
		while (p[0].x < p[1].x)
		{
			p[0].y = ft_equline(p[1], pendant, p[0].x, 0);
			ft_point(ft_newpoint(p[0].x++, -p[0].y), mlx, ft_get_color(h,
				h2, cuant, num++));
		}
		return ;
	}
	while (p[0].x > p[1].x)
	{
		p[0].y = ft_equline(p[1], pendant, p[0].x, 0);
		ft_point(ft_newpoint(p[0].x--, -p[0].y), mlx, ft_get_color(h,
			h2, cuant, num++));
	}
}

void		ft_line(t_point *p, void *mlx, int height, int height2)
{
	t_point points[2];

	points[0] = ft_newpoint(p[0].x, -p[0].y);
	points[1] = ft_newpoint(p[1].x, -p[1].y);
	if (labs(p[0].x - p[1].x) < labs(p[0].y - p[1].y))
		return (vertical_draw(points, mlx, height, height2));
	else
		return (horizontal_draw(points, mlx, height, height2));
}

