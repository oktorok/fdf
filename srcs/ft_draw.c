/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:36:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/17 07:56:29 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double dectorad(int hex)
{
    double rad;

    rad = (double)hex * M_PI / 180.0;
    return (rad);
}

static t_point		set_axi(int i)
{
	if (!i)
		return (ft_newpoint(1, 0, 0));
	else if (i == 1)
		return (ft_newpoint(0, 1, 0));
	else 
		return (ft_newpoint(0, 0, 1));
}

static t_point		ft_rotator(t_point p, int *angle, t_point origen)
{
	t_point	rot;
	t_point tmp;
	t_point	axi;
	int		i;
	double	rads;

	i = 3;
	rot.x = p.x;
	rot.y = p.y;
	rot.z = p.z;
	while (--i >= 0)
	{
		axi = set_axi(i);
		rads = dectorad(angle[i]);
		tmp.x =
			(cos(rads) + axi.x * (1.0 - cos(rads))) * rot.x +
			(-axi.z * sin(rads)) * rot.y +
			(axi.y * sin(rads)) * rot.z;
		tmp.y =
			(axi.z * sin(rads)) * rot.x +
			(cos(rads) + axi.y * (1.0 - cos(rads))) * rot.y +
			(-axi.x * sin(rads)) * rot.z;
		tmp.z =
			(-axi.y * sin(rads)) * rot.x +
			(axi.x * sin(rads)) * rot.y +
			(cos(rads) + axi.z * (1.0 - cos(rads))) * rot.z;
		rot = tmp;
	}
	rot.x += origen.x;
	rot.y += origen.y;
	rot.z += origen.z;
	return (rot);
}

int		ft_draw(void *mlx)
{
	t_params	*par;
	par = ((t_mlx *)mlx)->params;
	static t_point		x_vec = {40, 0, 0};
	static t_point		y_vec = {0, 40, 0};
	static t_point		z_vec = {0, 0, 40};
	t_point		origen;

	origen = par->true_origen;

	x_vec = ft_rotator(x_vec, par->angle, origen);
	y_vec = ft_rotator(y_vec, par->angle, origen);
	z_vec = ft_rotator(z_vec, par->angle, origen);

	par->angle[0] = 0;
	par->angle[1] = 0;
	par->angle[2] = 0;
//	y_vec = rotar_sobrex(y_vec, par->angle[0]);
//	y_vec = rotar_sobrey(y_vec, par->angle[1]);
//	y_vec = rotar_sobrez(y_vec, par->angle[2]);


ft_printf("\n[          ]\nx = \t (%f, %f, %f)\ny = \t (%f, %f, %f)\nz = \t (%f, %f, %f)\n[          ]\n",x_vec.x, x_vec.y, x_vec.z, y_vec.x,y_vec.y,y_vec.z,z_vec.x,z_vec.y,z_vec.z);


	ft_line(origen, x_vec, mlx, 0x0000FF);

	ft_line(origen, y_vec, mlx, 0x00FF00);

	ft_line(origen, z_vec, mlx, 0xFF0000);

x_vec.x -= origen.x;
x_vec.y -= origen.y;
x_vec.z -= origen.z;
y_vec.x -= origen.x;
y_vec.y -= origen.y;
y_vec.z -= origen.z;
z_vec.x -= origen.x;
z_vec.y -= origen.y;
z_vec.z -= origen.z;

	return (0);
}
