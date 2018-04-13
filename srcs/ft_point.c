/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 01:03:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/13 18:41:57 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define POINT_SIZE 0

void	ft_point(t_point point, void *mlx, int col)
{
	int i;
	int j;

	i = point.x - POINT_SIZE;
	while (i <= point.x + POINT_SIZE)
	{
		j = point.y - POINT_SIZE;
		while (j <= point.y + POINT_SIZE)
		{
			mlx_pixel_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win, i, j, col);
			j++;
		}
		i++;
	}
}
