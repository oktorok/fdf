/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:57:22 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/06 03:05:37 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void draw_y(void *mlx, t_point *extrems, t_point origen, int max)
{
	int i;
	int j;
	int *pixel;
	t_point *tmp_pnt;

	tmp_pnt = (t_point *)ft_memalloc(sizeof(t_point) * 3);
	pixel = ((t_mlx *)mlx)->pixel;
	i = -1;
	while (++i < pixel[1])
	{
		j = i + 2;
		tmp_pnt[0] = ft_newpoint(origen.x + max * i, ft_equline(origen,
					ft_pendant(origen, extrems[1]), origen.x + max * i));
		tmp_pnt[1] = ft_newpoint(tmp_pnt[0].x, tmp_pnt[0].y - pixel[j]);
		while (tmp_pnt[1].x != origen.x + max * i - (pixel[0] - 1) * max)
		{
			tmp_pnt[2] = ft_newpoint(tmp_pnt[1].x - max, ft_equline(tmp_pnt[0],
						ft_pendant(origen, extrems[0]), tmp_pnt[1].x - max) -
					(pixel[(j += pixel[1] + 1)]));
			ft_line(tmp_pnt[1], tmp_pnt[2], mlx);
			tmp_pnt[1] = tmp_pnt[2];
		}
	}
	ft_memdel((void **)&tmp_pnt);
}

static void draw_x(void *mlx, t_point *extrems, t_point origen, int max)
{
	int i;
	int j;
	int *pixel;
	t_point *tmp_pnt;

	tmp_pnt = (t_point *)ft_memalloc(sizeof(t_point) * 3);
	j = 2;
	i = -1;
	pixel = ((t_mlx *)mlx)->pixel;
	while (++i < pixel[0])
	{
		tmp_pnt[0] = ft_newpoint(origen.x - max * i, ft_equline(origen,
					ft_pendant(origen, extrems[0]), origen.x - max * i));
		tmp_pnt[1] = ft_newpoint(tmp_pnt[0].x, tmp_pnt[0].y - pixel[j++]);
		while (tmp_pnt[1].x != origen.x - max * i + (pixel[1] - 1) * max)
		{
			tmp_pnt[2] = ft_newpoint(tmp_pnt[1].x + max, ft_equline(tmp_pnt[0],
						ft_pendant(origen, extrems[1]), tmp_pnt[1].x + max) -
					(pixel[j++]));
			ft_line(tmp_pnt[1], tmp_pnt[2], mlx);
			tmp_pnt[1] = tmp_pnt[2];
		}
		j++;
	}
	ft_memdel((void **)&tmp_pnt);
}

static void coder(int code, t_point *origen, int *angle, int *max)
{
	if (code == 65361)
		origen->x -= 10;
	else if (code == 65364)
		origen->y += 10;
	else if (code == 65363)
		origen->x += 10;
	else if (code == 65362)
		origen->y -= 10;
	else if (code == 97)
		*max -= 10;
	else if (code == 100)
		*max += 10;
	else if (code == 113)
		*angle += 10;
	else if (code == 101)
		*angle -= 10;
}

int		ft_draw(void *mlx, int code)
{
	static t_point	*origen = NULL;
	static int		angle = 120;
	static int		max = 40;
	t_point			*extrems;
	int				*pixel;

	pixel = ((t_mlx *)mlx)->pixel;
	if (!origen)
	{
		origen = (t_point *)ft_memalloc(sizeof(t_point));
		*origen = ft_newpoint(500, 0);
	}
	if (code == 65361 || code == 65362 || code == 65363 ||
			code == 65364 || code == 113 || code == 101 || code == 97 || code == 100)
		ft_clear(mlx);
	coder(code, origen, &angle, &max);
	extrems = (t_point *)ft_memalloc(sizeof(t_point) * 2);
	*extrems = ft_rotatepoint(ft_newpoint(origen->x, 0) , *origen, angle);
	*(extrems + 1) = ft_rotatepoint(*extrems, *origen, 360 - 2 * angle);
	draw_x(mlx, extrems, *origen, max);
	draw_y(mlx, extrems, *origen, max);
	return (0);
}
