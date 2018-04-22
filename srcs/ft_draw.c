/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 02:36:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/22 04:58:27 by jagarcia         ###   ########.fr       */
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
		if (i + 1 < px[-2])
		{
			t[1] = ft_vadd(or, ft_vset(sr, i + 1, j, px[(i + 1) * px[-1] + j]));
			ft_line(t, mlx, px[i * px[-1] + j], px[(i + 1) * px[-1] + j]);
		}
		if (j + 1 < px[-1])
		{
			t[1] = ft_vadd(or, ft_vset(sr, i, j + 1, px[i * px[-1] + j + 1]));
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
	vector = ((t_mlx *)mlx)->vector;
	origen = ft_vrest(origen, ft_vset(vector, pixel[0] / 2, pixel[1] / 2, 0));
	
	drawer(ft_isometric(vector), pixel + 2, origen, mlx);
	return (0);
}
