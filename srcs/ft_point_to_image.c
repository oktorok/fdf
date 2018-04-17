/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 01:03:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/17 01:59:11 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_point_to_image(t_point point, void *mlx, int col)
{
	int		*addrs;
	int		size_line;
	int		pos;

	if (point.x >= ((t_mlx *)mlx)->params->win_size.x || point.x < 0 ||
			point.y >= ((t_mlx *)mlx)->params->win_size.y || point.y < 0)
		return ;
	size_line = ((t_mlx *)mlx)->params->win_size.x;
	addrs = (int *)(((t_mlx *)mlx)->addrs);
	pos = point.y * size_line + point.x;
	addrs[pos] = col;
}
