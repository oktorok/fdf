/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 01:03:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/25 01:50:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define POINT_SIZE 5

void	ft_point(int x, int y, void *mlx, int col)
{
	int i;
	int j;

	i = x - POINT_SIZE;
	while (i < x + POINT_SIZE)
	{
		j = y - POINT_SIZE;
		while (j < y + POINT_SIZE)
		{
			mlx_pixel_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win, i, j, col);
			j++;
		}
		i++;
	}
}
