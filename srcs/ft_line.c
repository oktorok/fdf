/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/03 00:51:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void swap_point(t_point *p1, t_point *p2)
{
	t_point tmp;

	tmp = ft_newpoint(p1->x, p1->y);
	*p1 = ft_newpoint(p2->x, p2->y);
	*p2 = ft_newpoint(tmp.x, tmp.y);
}

static void vertical_draw(t_point *p, void *mlx, int height, int height2)
{
	double	pendant;
	t_point	p1;
	t_point	p2;
	int		cuant;
	int		num;

	p1 = ft_newpoint(p[0].x, -p[0].y);
	p2 = ft_newpoint(p[1].x, -p[1].y);
//		swap_point(&p1, &p2);
	pendant = ft_pendant(p1, p2);
	cuant = labs(p2.y - p1.y) + 1;
	num = 1;
	if (p1.y < p2.y)
	{
		while (p1.y < p2.y)
		{
			p1.x = ((p1.y - p2.y) / pendant) + p2.x;
			ft_point(ft_newpoint(p1.x, -p1.y), mlx, ft_get_color(height, height2, cuant, num));
			p1.y++;
			num++;
		}
	}
	while (p1.y > p2.y)
	{
		p1.x = ((p1.y - p2.y) / pendant) + p2.x;
		ft_point(ft_newpoint(p1.x, -p1.y), mlx, ft_get_color(height, height2, cuant, num));
		p1.y--;
		num++;
	}
}

void		ft_line(t_point *p, void *mlx, int height, int height2)
{
	double	pendant;
	t_point p1;
	t_point p2;
	int		cuant;
	int		num;

	if (labs(p[0].x - p[1].x) < labs(p[0].y - p[1].y))
	{
		vertical_draw(p, mlx, height, height2);
		return ;
	}
	p1 = ft_newpoint(p[0].x, -p[0].y);
	p2 = ft_newpoint(p[1].x, -p[1].y);
	//	swap_point(&p1, &p2);
	pendant = ft_pendant(p1, p2);
	cuant = labs(p1.x - p2.x) + 1;
	num = 1;
	if (p1.x < p2.x)
	{
		while (p1.x < p2.x)
		{
			p1.y = ft_equline(p2, pendant, p1.x);
			ft_point(ft_newpoint(p1.x, -p1.y), mlx, ft_get_color(height, height2, cuant, num));
			p1.x++;
			num++;
		}
		return ;
	}
	while (p1.x > p2.x)
	{
		p1.y = ft_equline(p2, pendant, p1.x);
		ft_point(ft_newpoint(p1.x, -p1.y), mlx, ft_get_color(height, height2, cuant, num));
		p1.x--;
		num++;
	}
	return ;
}
