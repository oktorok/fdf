/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:35:09 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/22 04:06:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double dectorad(int hex)
{
	double rad;

	rad = (double)hex * M_PI / 180.0;
	return (rad);
}

t_point	  ft_rotator(t_point rot_pnt, int angle, t_point rot_axi)
{
	t_point rot;
	double  rads;
	double	coseno;
	double	seno;

	if ((rads = ft_vnorm(rot_axi)) != 1)
		rot_axi = ft_vprodbyscal(rot_axi, 1.0 / rads);
	rads = dectorad(angle);
	coseno = 1.0 - cos(rads);
	seno = sin(rads);
	rot.x =
		(-(coseno - 1.0) + pow(rot_axi.x, 2) * coseno) * rot_pnt.x +
		(rot_axi.x * rot_axi.y * coseno - rot_axi.z * seno) * rot_pnt.y +
		(rot_axi.x * rot_axi.z * coseno + rot_axi.y * seno) * rot_pnt.z;
	rot.y =
		(rot_axi.y * rot_axi.x * coseno + rot_axi.z * seno) * rot_pnt.x +
		(-(coseno - 1.0) + pow(rot_axi.y, 2) * coseno) * rot_pnt.y +
		(rot_axi.y * rot_axi.z * coseno - rot_axi.x * seno) * rot_pnt.z;
	rot.z =
		(rot_axi.z * rot_axi.x * coseno - rot_axi.y * seno) * rot_pnt.x +
		(rot_axi.z * rot_axi.y * coseno + rot_axi.x * seno) * rot_pnt.y +
		(-(coseno - 1.0) + pow(rot_axi.z, 2) * coseno) * rot_pnt.z;
	return (rot);
}
