/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotatepoint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:14:32 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/04 00:45:31 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double hextorad(int hex)
{
	double rad;

	rad = (double)hex * M_PI / 180.0;
	return (rad);
}

t_point		ft_rotatepoint(t_point point, t_point origin, int grades)
{
	t_point new_point;
	int		new_x;
	int		new_y;
	double	rad;

	rad = hextorad(grades);
	point.x -= origin.x;
	point.y = -point.y + origin.y;
	new_x = (double)point.x * cos(rad) - (double)point.y * sin(rad);
	new_y = (double)point.x * sin(rad) + (double)point.y * cos(rad);
	new_point = ft_newpoint(new_x + origin.x, -(new_y - origin.y));
	return (new_point);
}
