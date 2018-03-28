/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/28 13:19:44 by jagarcia         ###   ########.fr       */
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
	if (p2.y < p1.y)
		swap_point(&p1, &p2);
	pendant = ft_pendant(p1, p2);
	cuant = p2.y - p1.y;
	num = 1;
	while (p1.y < p2.y)
	{
		num++;
		p1.x = ((p1.y - p2.y) / pendant) + p2.x;
		ft_point(ft_newpoint(p1.x, -p1.y), mlx, ft_get_color(height, height2, cuant, num));
		p1.y++;
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
	if (p1.x < p2.x)
		swap_point(&p1, &p2);
	pendant = ft_pendant(p1, p2);
	cuant = p1.x - p2.x;
	num = 1;
	while (p2.x < p1.x)
	{
		num++;
		p2.y = ft_equline(p1, pendant, p2.x);
		ft_point(ft_newpoint(p2.x, -p2.y), mlx, ft_get_color(height, height2, cuant, num));
		p2.x++;
	}
	return ;
}
