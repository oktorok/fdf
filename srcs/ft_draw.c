/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 01:57:22 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/18 09:00:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	make_vector(t_point origen, double pendant, int magnitud)
{
	t_point vector;
	t_point	orig_carte;

	printf("\nPENDIENTE = %f\n",pendant);
	orig_carte = ft_newpoint(0, 0);
	vector = orig_carte;
	if (isinf(pendant))
		vector.y = magnitud;
	else
		while (hypot(vector.x, vector.y) <= magnitud)
		{
			vector.x++;
			vector.y = ft_equline(orig_carte, pendant, vector.x);
		}
//	if (pendant < 0)
//		vector = ft_newpoint(-vector.x, vector.y);
//	vector.y = -vector.y;
	return (vector);
}

static void	draw_y(void *mlx, t_point *extrems, t_point origen, t_point *sep_vtr)
{
	int		i;
	int		j;
	int		*pixel;
	t_point	*tmp_pnt;

	tmp_pnt = (t_point *)ft_memalloc(sizeof(t_point) * 3);
	pixel = ((t_mlx *)mlx)->pixel;
	i = -1;
	while (++i < pixel[1])
	{
		j = i + 2;
		tmp_pnt[0] = ft_newpoint(origen.x + sep_vtr[0].x * i, origen.y + sep_vtr[0].y * i);
		tmp_pnt[1] = ft_newpoint(tmp_pnt[0].x, tmp_pnt[0].y - (pixel[j]) * 5);
		j += pixel[1];
		while ((j - 2) < pixel[0] * pixel[1])
		{
			tmp_pnt[2] = ft_newpoint(tmp_pnt[1].x - sep_vtr[1].x, tmp_pnt[1].y -
					sep_vtr[1].y + (pixel[j - pixel[1]] - pixel[j]) * 5);
			ft_line(tmp_pnt[1], tmp_pnt[2], mlx);
			tmp_pnt[1] = tmp_pnt[2];
			j += pixel[1];
		}
	}
	ft_memdel((void **)&tmp_pnt);
}

static void	draw_x(void *mlx, t_point *extrems, t_point origen, t_point *sep_vtr)
{
	int		i;
	int		j;
	int		*pixel;
	t_point	*tmp_pnt;

	tmp_pnt = (t_point *)ft_memalloc(sizeof(t_point) * 3);
	i = -1;
	pixel = ((t_mlx *)mlx)->pixel;
	while (++i < pixel[0])
	{
		j = pixel[1] * i + 2;
		tmp_pnt[0] = ft_newpoint(origen.x - sep_vtr[1].x * i, origen.y - sep_vtr[1].y * i);
		ft_printf("vector(%i, %i)\n", sep_vtr[0].x,sep_vtr[0].y);
		ft_printf("pnt0(%i, %i)\n", tmp_pnt[0].x,tmp_pnt[0].y);
		tmp_pnt[1] = ft_newpoint(tmp_pnt[0].x, tmp_pnt[0].y - (pixel[j++] * 5));
		while (j < pixel[1] * (i + 1) + 2)	
		{
			tmp_pnt[2] = ft_newpoint(tmp_pnt[1].x + sep_vtr[0].x, tmp_pnt[1].y + sep_vtr[0].y + (pixel[j - 1] - pixel[j]) * 5);
			ft_printf("pnt1 (%i, %i)\npnt2 (%i, %i)\n\n",tmp_pnt[1].x,tmp_pnt[1].y,tmp_pnt[2].x,tmp_pnt[2].y);
			ft_line(tmp_pnt[1], tmp_pnt[2], mlx);
			tmp_pnt[1] = tmp_pnt[2];
			j++;
		}
	}
	ft_memdel((void **)&tmp_pnt);
}

static void	coder(int code, t_point *origen, int *angle, int *max)
{
	if (code == 123)
		origen->x -= 10;
	else if (code == 125)
		origen->y += 10;
	else if (code == 124)
		origen->x += 10;
	else if (code == 126)
		origen->y -= 10;
	else if (code == 12)
		*max -= 10;
	else if (code == 13)
		*max += 10;
	else if (code == 0)
		*angle += 10;
	else if (code == 1)
		*angle -= 10;
}

int			ft_draw(void *mlx, int code)
{
	static t_point	*origen = NULL;
	static int		angle = 120;
	static int		max = 40;
	t_point			*extrems;
	static int		i = 0;
	t_point *sep_vtr;
	double pendant;

	if (!origen)
	{
		origen = (t_point *)ft_memalloc(sizeof(t_point));
		*origen = ft_newpoint(500, 100);
	}
	if (code == 126 || code == 124 || code == 125 ||
			code == 123 || code == 12 || code == 13 ||
			code == 0 || code == 1 || code == 6 || code == 7)
		ft_clear(mlx);
	coder(code, origen, &angle, &max);
	if (code == 6)
		i += 10;
	else if (code == 7)
		i -= 10;
	extrems = (t_point *)ft_memalloc(sizeof(t_point) * 2);
	*extrems = ft_rotatepoint(ft_newpoint(origen->x, 0), *origen, angle + i);
	*(extrems + 1) = ft_rotatepoint(ft_newpoint(origen->x, 0), *origen, 360 - (angle - i));
	ft_printf("\norigen = (%i,%i)\nextremo[0] = (%i,%i)\t extremo[1] = (%i,%i)\n[ANGULO 1:%i\tANGULO2:%i]\n",origen->x,origen->y,extrems[0].x,extrems[0].y,extrems[1].x,extrems[1].y, angle + i, 360 - (angle - i));
	ft_point(*origen,mlx,0xff5510);
	ft_point(extrems[0],mlx,0xAA0010);
	ft_point(extrems[1],mlx,0xAAff10);

	sep_vtr = (t_point *)ft_memalloc(sizeof(t_point) * 2);
	pendant = ft_pendant(*origen, extrems[1]);
	sep_vtr[0] = make_vector(*origen, pendant, max);
	if ((360 - (angle - i) < 180))
		sep_vtr[0] = ft_newpoint(-sep_vtr[0].x, -sep_vtr[0].y);
//	if (360 - (angle - i) < 360 && angle + i >= 180)
//		sep_vtr[0] = ft_newpoint(-sep_vtr[0].x, -sep_vtr[0].y);
	pendant = ft_pendant(*origen, extrems[0]);
	sep_vtr[1] = make_vector(*origen, pendant, max);
	if ((angle + i < 0))
		sep_vtr[1] = ft_newpoint(-sep_vtr[1].x, -sep_vtr[1].y);
	draw_x(mlx, extrems, *origen, sep_vtr);
//	draw_y(mlx, extrems, *origen, sep_vtr);
	return (0);
}
