/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:57:22 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/13 18:36:52 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	make_vector(t_params params, int angle)
{
	t_point		vector;
	t_point		origen_cart;
	double		pendant;

	origen_cart = ft_newpoint(0, 0);
	vector = origen_cart;
	pendant = ft_pendant(origen_cart, ft_rotatepoint(ft_newpoint(0,
					params.true_origen.x), origen_cart, angle));
	if (isinf(pendant))
		vector.y = params.square_side;
	else
		while (hypot(vector.x, vector.y) <= params.square_side)
			vector.y = ft_equline(origen_cart, pendant, ++vector.x, 0);
	return (ft_rotatepoint(vector, origen_cart, params.turn));
}

static void		draw_y(void *mlx, t_point origen, t_point *vector, t_params par)
{
	int					i;
	int					j;
	int					*pixel;
	t_point				*tmp;
	t_point				vector_z;
	
	if (!(tmp = (t_point *)ft_memalloc(sizeof(t_point) * 3)))
		ft_error(NULL);
	pixel = (int *)((t_mlx *)mlx)->pixel;
	i = -1;
	while (++i < pixel[1])
	{
		j = i + 2;
		vector_z = ft_newpoint(par.vector_z.x * -pixel[j] * par.height, par.vector_z.y * -pixel[j] * par.height);
		tmp[0] = ft_newpoint(origen.x + vector[0].x * i, origen.y + vector[0].y * i);
		tmp[1] = ft_newpoint(tmp[0].x + vector_z.x, tmp[0].y + vector_z.y);
		j += pixel[1];
		while ((j - 2) < pixel[0] * pixel[1])
		{
			vector_z = ft_newpoint(par.vector_z.x * -(pixel[j - pixel[1]] - pixel[j]) * par.height, par.vector_z.y * -(pixel[j - pixel[1]] - pixel[j]) * par.height);
			tmp[2] = ft_newpoint(tmp[1].x - vector[1].x - vector_z.x, tmp[1].y - vector[1].y - vector_z.y);
			ft_line(tmp + 1, mlx, pixel[j - pixel[1]], pixel[j]);
			tmp[1] = tmp[2];
			j += pixel[1];
		}
	}
	ft_memdel((void **)&tmp);
}

static void		draw_x(void *mlx, t_point origen, t_point *vector, t_params par)
{
	int					i;
	int					j;
	int					*pixel;
	t_point				*tmp;
	t_point				vector_z;

	if (!(tmp = (t_point *)ft_memalloc(sizeof(t_point) * 3)))
			ft_error(NULL);
	i = -1;
	pixel = (int *)((t_mlx *)mlx)->pixel;
	while (++i < pixel[0])
	{
		j = pixel[1] * i + 2;
		vector_z = ft_newpoint(par.vector_z.x * -pixel[j] * par.height, par.vector_z.y * -pixel[j] * par.height);
		tmp[0] = ft_newpoint(origen.x - vector[1].x * i, origen.y - vector[1].y * i);
		tmp[1] = ft_newpoint(tmp[0].x + vector_z.x, tmp[0].y + vector_z.y);
		j++;
		while (j < pixel[1] * (i + 1) + 2)	
		{
			vector_z = ft_newpoint(par.vector_z.x * -(pixel[j - 1] - pixel[j]) * par.height, par.vector_z.y * -(pixel[j - 1] - pixel[j]) * par.height);
			tmp[2] = ft_newpoint(tmp[1].x + vector[0].x - vector_z.x, tmp[1].y + vector[0].y - vector_z.y);
			ft_line(tmp + 1, mlx, pixel[j - 1], pixel[j]);
			tmp[1] = tmp[2];
			j++;
		}
	}
	ft_memdel((void **)&tmp);
}

static t_point	calc_origen(t_mlx *mlx, t_point *vector)
{
	int	*pix;
	t_params *params;
	t_point tmp;

	pix = mlx->pixel;
	params = mlx->params;
	tmp = ft_newpoint(params->true_origen.x, params->true_origen.y);
	tmp.x += vector[1].x * (pix[0] - 1) / 2 - vector[0].x * (pix[1] - 1) / 2;
	tmp.y += vector[1].y * (pix[0] - 1) / 2 - vector[0].y * (pix[1] - 1) / 2;
	return (tmp);
}

int			ft_draw(void *mlx)
{
	t_params		*params;
	t_point			origen;
	t_point			*vector;

	params = ((t_mlx *)mlx)->params;
	vector = (t_point *)ft_memalloc(sizeof(t_point) * 2);
	vector[0] = make_vector(*params, params->angle[1]);
	vector[1] = make_vector(*params, params->angle[0]);
	if ((params->angle[1] < 180))
		vector[0] = ft_newpoint(-vector[0].x, -vector[0].y);
	if ((params->angle[0] >= 180))
		vector[1] = ft_newpoint(-vector[1].x, -vector[1].y);
	origen = calc_origen(mlx, vector);
	params->vector_z = ft_rotatepoint(ft_newpoint(0, 5), ft_newpoint(0, 0), params->angle[0] - 120 + params->angle[1] - 240);
	draw_x(mlx, origen, vector, *params);
	draw_y(mlx, origen, vector, *params);
	return (0);
}
