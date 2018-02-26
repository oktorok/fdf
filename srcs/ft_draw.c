/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 11:44:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/26 20:24:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define DESF 50
int	ft_draw(void *mlx, int code)
{
	int *pix;
	int colum;
	int row;
	int i;
	t_point p1;
	t_point p2;
	t_point	desfase;

	i = 0;
	colum = 1;
	pix = (((t_mlx *)mlx)->pixel);
	while (pix[i++] != -2)
			colum++;
	row = 1;
	while (pix[i] != -1)
	{
		if (pix[i++] == -2)
			row++;
	}
	i = 0;
	desfase = ft_newpoint(100, 100);
	ft_printf("FILAS: %i\nCOLUMNAS: %i\n", row, colum);
	while (pix[i] != -1)
	{
		if (pix[i] != -2)
		{
			p1 = ft_newpoint((DESF * ((i % colum) + 1)) + desfase.x, (DESF * ((i / colum) + 1)) + desfase.y);
			if (i / colum)
			{
				p2 = ft_newpoint((DESF * ((i % colum) + 1)) + desfase.x, (DESF * (i / colum)) + desfase.y);
				ft_draw_line(p1, p2, mlx);
			}
			i++;
			if (pix[i] != -2)
			{
				p2 = ft_newpoint(DESF * ((i % colum) + 1) + desfase.x, (DESF * ((i / colum) + 1)) + desfase.y);
				ft_draw_line(p1, p2, mlx);
			}
			else
				ft_point(p1.x, p1.y, mlx, 0xffffff);
		}
		else
		{
		//	desfase.x -=10;
		//	desfase.y -= 5;
			i++;
		}
	}
//	p2 = ft_newpoint(400,200);
//	ft_draw_line(p1,p2,mlx);
	return (1);
}
