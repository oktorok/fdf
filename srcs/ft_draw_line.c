/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_eq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/25 01:54:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_draw_line(t_point p1, t_point p2, void *mlx)
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
	x = p2.x;
    pendant =  (p1.y - p2.y) / (p1.x - p2.x);
	while (x < p1.x)
	{
		y = (p2.y + pendant * (x - p2.x));
		if (p1.x == 450)
			ft_point(x, y, mlx, 0xFFFFFF);
		else
			ft_circle(x, y, mlx, 0xFFFFFF);
		x++;
	}
	return ;
}
