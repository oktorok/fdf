/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_eq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/26 17:44:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_colum(t_point p1, t_point p2, void *mlx)
{
	int		x;
	int		y;

	y = p2.y;
	x = p1.x;
	while (y < p1.y)
	{
		ft_point(x, y, mlx, 0xFFFFFF);
		y++;
	}
	return ;
}

void		ft_draw_line(t_point p1, t_point p2, void *mlx)
{
    int	pendant;
	t_point	tmp;
    int		x;
	int		y;

	if (p1.x < p2.x)
	{
		tmp = ft_newpoint(p1.x, p1.y);
		p1 = ft_newpoint(p2.x, p2.y);
		p2 = ft_newpoint(tmp.x, tmp.y);
	}
	else if (p1.x == p2.x)
	{
		draw_colum(p1, p2, mlx);
		return ;
	}
	pendant =  (p1.y - p2.y) / (p1.x - p2.x);
	x = p2.x;
	while (x < p1.x)
	{
		y = (p2.y + pendant * (x - p2.x));
		ft_point(x, y, mlx, 0xFFFFFF);
		x++;
	}
	return ;
}
