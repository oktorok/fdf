/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:36:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/26 05:49:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		limit(t_point *p, t_point size)
{
	if ((p[0].x >= size.x || p[0].x <= 0 || p[0].y < 0 || p[0].y >= size.y) &&
			(p[1].x >= size.x || p[1].x <= 0 || p[1].y < 0 || p[1].y >= size.y))
		return (0);
	return (1);
}

static t_point	set_pnt(t_mlx *mlx, t_point real_pnt, t_point origen,
		t_point *sr)
{
	t_point final;

	final = ft_vadd(origen, ft_vset(sr, real_pnt.x, real_pnt.y, real_pnt.z));
	if (mlx->params->proyection == 4)
		ft_conic(&final);
	return (final);
}

static void		drawer(t_point *sr, int *px, t_point or, t_mlx *mlx)
{
	t_point t[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < px[-2])
	{
		t[0] = set_pnt(mlx, ft_newpoint(i, j, px[i * px[-1] + j]), or, sr);
		t[1] = set_pnt(mlx, ft_newpoint(i + 1, j, px[(i + 1) * px[-1] + j]),
				or, sr);
		if (i + 1 < px[-2] && (limit(t, mlx->params->win_size)))
			ft_line(t, mlx, px[i * px[-1] + j], px[(i + 1) * px[-1] + j]);
		t[1] = set_pnt(mlx, ft_newpoint(i, j + 1, px[i * px[-1] + j + 1]),
				or, sr);
		if (j + 1 < px[-1] && (limit(t, mlx->params->win_size)))
			ft_line(t, mlx, px[i * px[-1] + j], px[i * px[-1] + j + 1]);
		if (j + 1 >= px[-1])
			i++;
		j = (j + 1) >= px[-1] ? 0 : (j + 1);
	}
}

int				ft_draw(t_mlx *mlx)
{
	t_point		origen;
	int			*pixel;
	t_point		*vector;

	pixel = mlx->pixel;
	origen = mlx->params->true_origen;
	if (!(vector = (t_point *)ft_memalloc(sizeof(t_point) * 3)))
		ft_error(NULL);
	vector[0] = (mlx->vector)[0];
	vector[1] = (mlx->vector)[1];
	vector[2] = (mlx->vector)[2];
	if (mlx->params->proyection == 1)
		ft_isometric(vector);
	else if (mlx->params->proyection == 2)
		ft_cabinet(vector);
	else if (mlx->params->proyection == 3)
		ft_cavaliere(vector);
	origen = ft_vrest(origen, ft_vset(vector, pixel[0] / 2, pixel[1] / 2, 0));
	drawer(vector, pixel + 2, origen, mlx);
	ft_memdel((void **)&vector);
	return (0);
}
