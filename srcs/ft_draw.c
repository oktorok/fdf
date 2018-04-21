/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:36:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/21 05:10:35 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point set_pnt(t_point *sist_ref, int x, int y, int z)
{
	t_point x_pos;
	t_point y_pos;
	t_point z_pos;
	
	x_pos = ft_vprodbyscal(sist_ref[0], x);
	y_pos = ft_vprodbyscal(sist_ref[1], y);
	z_pos = ft_vprodbyscal(sist_ref[2], z);
	return (ft_vadd(ft_vadd(x_pos, y_pos), z_pos));
}

static int drawer(t_point *sr, int *px, t_point or, void *mlx)
{
	t_point t[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < px[-2])
	{
		t[0] = ft_vadd(or, set_pnt(sr, i, j, px[i * px[-1] + j]));
		if (i + 1 < px[-2])
		{
			t[1] = ft_vadd(or, set_pnt(sr, i + 1, j, px[(i + 1) * px[-1] + j]));
			ft_line(t, mlx, px[i * px[-1] + j], px[(i + 1) * px[-1] + j]);
		}
		if (j + 1 < px[-1])
		{
			t[1] = ft_vadd(or, set_pnt(sr, i, j + 1, px[i * px[-1] + j + 1]));
			ft_line(t, mlx, px[i * px[-1] + j], px[i * px[-1] + j + 1]);
		}
		if (++j >= px[-1])
		{
			j = 0;
			i++;
		}
	}
	return (0);
}

int	ft_draw(void *mlx)
{
	t_point		origen;
	int 		*pixel;
	t_point		*vector;
//	t_point		*vector_zoom;

	pixel = ((t_mlx *)mlx)->pixel;
	origen = ((t_mlx *)mlx)->params->true_origen;
	vector = ((t_mlx *)mlx)->vector;
//	vector_zoom = (t_point *)ft_memalloc(sizeof(t_point) * 3);
//	vector_zoom = ft_memcpy(vector_zoom,
//			((t_mlx *)mlx)->vector, sizeof(t_point) * 3);
/*	vector_zoom[0] = ft_vprodbyscal(vector_zoom[0],
			((t_mlx *)mlx)->params->cube_side);
	vector_zoom[1] = ft_vprodbyscal(vector_zoom[1],
			((t_mlx *)mlx)->params->cube_side);
	vector_zoom[2] = ft_vprodbyscal(vector_zoom[2],
			((t_mlx *)mlx)->params->cube_side);*/
	origen = ft_vrest(origen, set_pnt(vector,
				pixel[0] / 2, pixel[1] / 2, 0));
	drawer(vector, pixel + 2, origen, mlx);
//	ft_memdel((void **)&vector_zoom);
	return (0);
}
