/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:36:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/18 04:56:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double dectorad(int hex)
{
    double rad;

    rad = (double)hex * M_PI / 180.0;
    return (rad);
}

static t_point		set_axi_angle(int i, t_point angle, int *tmpangle)
{
	if (!i)
	{
		*tmpangle = angle.x;
		return (ft_newpoint(1, 0, 0));
	}
	else if (i == 1)
	{
		*tmpangle = angle.y;
		return (ft_newpoint(0, 1, 0));
	}
	*tmpangle = angle.z;
	return (ft_newpoint(0, 0, 1));
}

static t_point		ft_rotator(t_point p, t_point angle, t_point origen)
{
	t_point	rot;
	t_point	axi;
	int		i;
	double	rads;
	int		angletmp;

	i = -1;
	rot = p;
	while (++i < 3)
	{
		axi = set_axi_angle(i, angle, &angletmp);
		rads = dectorad(angletmp);
		ft_printf("\nangulo %i =\t%.15f\n",i,rads);
		p.x =
			(cos(rads) + axi.x * (1.0 - cos(rads))) * rot.x +
			(-axi.z * sin(rads)) * rot.y +
			(axi.y * sin(rads)) * rot.z;
		p.y =
			(axi.z * sin(rads)) * rot.x +
			(cos(rads) + axi.y * (1.0 - cos(rads))) * rot.y +
			(-axi.x * sin(rads)) * rot.z;
		p.z =
			(-axi.y * sin(rads)) * rot.x +
			(axi.x * sin(rads)) * rot.y +
			(cos(rads) + axi.z * (1.0 - cos(rads))) * rot.z;
		rot = p;
	}
	return (rot);
}

t_point	ft_traslation(t_point p, t_point vector)
{
	p.x += vector.x;
	p.y += vector.y;
	p.z += vector.z;
	return (p);
}

static t_point vectscalprod(t_point p, double n)
{
	return (ft_newpoint(p.x * n, p.y * n, p.z * n));
}

static t_point vectadd(t_point p, t_point q)
{
	return (ft_newpoint(p.x + q.x, p.y + q.y, p.z + q.z));
}

static t_point locate_point(t_point *sist_ref, int x, int y, int z)
{
	t_point x_pos;
	t_point y_pos;
	t_point z_pos;
	
	x_pos = vectscalprod(sist_ref[0], x);
	y_pos = vectscalprod(sist_ref[1], y);
	z_pos = vectscalprod(sist_ref[2], z);
	return (vectadd(vectadd(x_pos, y_pos), z_pos));
}

static int ft_drawx(t_point *vector, int *pixel, t_point origen, void *mlx)
{
	t_point tmp[2];
	int		i;
	int		j;

	i = 0;
	while (i < pixel[-2])
	{
		tmp[0] = vectadd(origen, locate_point(vector, i, j, pixel[i * pixel[-1] + j]));
		if (i + 1 < pixel[-2])
		{
			tmp[1] = vectadd(origen, locate_point(vector, i + 1, j, pixel[(i + 1) * pixel[-1] + j]));
			ft_line(tmp, mlx, pixel[i * pixel[-1] + j], pixel[(i + 1) * pixel[-1] + j]);
		}
		if (j + 1 < pixel[-1])
		{
			tmp[1] = vectadd(origen, locate_point(vector, i, j + 1, pixel[i * pixel[-1] + j + 1]));
			ft_line(tmp, mlx, pixel[i * pixel[-1] + j], pixel[i * pixel[-1] + j + 1]);
		}
		if (++j >= pixel[-1])
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

int	ft_draw(void *mlx)
{
	t_point		*vector;
	t_point		origen;
	t_params	*par;
	int 		*pixel;

	pixel = ((t_mlx *)mlx)->pixel;
	vector = ((t_mlx *)mlx)->vector;
	par = ((t_mlx *)mlx)->params;
	origen = par->true_origen;
	vector[0] = ft_rotator(vector[0], par->angle, origen);
	vector[1] = ft_rotator(vector[1], par->angle, origen);
	vector[2] = ft_rotator(vector[2], par->angle, origen);
	vector[0] = ft_traslation(vector[0], ft_newpoint(par->cube_side.x, 0, 0));
	vector[1] = ft_traslation(vector[1], ft_newpoint(0, par->cube_side.y, 0));
	vector[2] = ft_traslation(vector[2], ft_newpoint(0, 0, par->cube_side.z));
	par->angle = ft_newpoint(0, 0, 0);
	par->cube_side = ft_newpoint(0, 0, 0);
	ft_drawx(vector, pixel + 2, origen, mlx);
	return (0);
}
