/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/18 04:27:37 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_colum(t_point p1, t_point p2, void *mlx)
{
	int		x;
	int		y;

	y = -p2.y;
	x = p1.x;
	while (y < -p1.y)
	{
		ft_point(ft_newpoint(x, y), mlx, 0xFFFFFF);
		y++;
	}
	return ;
}

static void vertical_draw(t_point p1, t_point p2, void *mlx)
{
	int		x;
	int		y;
	t_point tmp;
	double	pendant;

	if (p2.y < p1.y)
	{
		tmp = ft_newpoint(p1.x, p1.y);
		p1 = ft_newpoint(p2.x, p2.y);
		p2 = ft_newpoint(tmp.x, tmp.y);
	}
	y = p1.y;
	pendant = ft_pendant(p1, p2);
	while (y < p2.y)
	{
		x = ((y - p2.y) / pendant) + p2.x;
		ft_point(ft_newpoint(x, -y), mlx, 0xFFFFFF);
		y++;
	}
}
void		ft_line(t_point p1, t_point p2, void *mlx)
{
	t_point	tmp;
    int		x;
	int		y;

	p1.y = -p1.y;
	p2.y = -p2.y;
	if (labs(p1.x - p2.x) < labs(p1.y - p2.y))
	{
		vertical_draw(p1, p2, mlx);
		return ;
	}
	if (p1.x < p2.x)
	{
		tmp = ft_newpoint(p1.x, p1.y);
		p1 = ft_newpoint(p2.x, p2.y);
		p2 = ft_newpoint(tmp.x, tmp.y);
	}
	if (p1.x == p2.x)
	{
		draw_colum(p1, p2, mlx);
		return ;
	}
	x = p2.x;
	while (x < p1.x)
	{
		y = ft_equline(p1, ft_pendant(p1, p2), x);
		ft_point(ft_newpoint(x, -y), mlx, 0xFFFFFF);
		x++;
	}
	return ;
}
