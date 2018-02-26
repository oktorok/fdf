/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 01:03:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/25 02:12:07 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RADI 3
void ft_circle(int x, int y, void *mlx, int color)
{
	int i;
	int j;

	i = x - RADI;
	while (i < x + RADI)
	{
		j = y - RADI;
		while (j < y + RADI)
		{
			if (pow(i - x, 2) + pow(j - y, 2) <= RADI)
				mlx_pixel_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win, i, j, color);
			j++;
		}
		i++;
	}
}
