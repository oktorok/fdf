/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:36:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/23 04:09:32 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int drawer(t_point *sr, int *px, t_point or, void *mlx)
{
	t_point t[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < px[-2])
	{
		t[0] = ft_vadd(or, ft_vset(sr, i, j, px[i * px[-1] + j]));
		ft_conic(t);
		if (i + 1 < px[-2])
		{
			t[1] = ft_vadd(or, ft_vset(sr, i + 1, j, px[(i + 1) * px[-1] + j]));
			ft_conic(t + 1);
			ft_line(t, mlx, px[i * px[-1] + j], px[(i + 1) * px[-1] + j]);
		}
		if (j + 1 < px[-1])
		{
			t[1] = ft_vadd(or, ft_vset(sr, i, j + 1, px[i * px[-1] + j + 1]));
			ft_conic(t + 1);
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

	pixel = ((t_mlx *)mlx)->pixel;
	origen = ((t_mlx *)mlx)->params->true_origen;
	vector = (t_point *)ft_memalloc(sizeof(t_point) * 3);
	vector[0] = (((t_mlx *)mlx)->vector)[0];
	vector[1] = (((t_mlx *)mlx)->vector)[1];
	vector[2] = (((t_mlx *)mlx)->vector)[2];
	if (((t_mlx *)mlx)->params->proyection == 1)
		ft_isometric(vector);
	else if (((t_mlx *)mlx)->params->proyection == 2)
		ft_cabinet(vector);
	else if (((t_mlx *)mlx)->params->proyection == 3)
		ft_cavaliere(vector);
	else if (((t_mlx *)mlx)->params->proyection == 4)
		ft_conic(vector);
	origen = ft_vrest(origen, ft_vset(vector, pixel[0] / 2, pixel[1] / 2, 0));
	drawer(vector, pixel + 2, origen, mlx);
	ft_memdel((void **)&vector);
	return (0);
}
