/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 01:03:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 01:14:13 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void print_to_legend(t_point point, t_mlx *mlx, int col)
{
	int		*addrs;
	int		size_line;
	int		pos;

	size_line = 100;
	addrs = (int *)(mlx->addrs_leg);
	pos = point.y * size_line + point.x;
	addrs[pos] = col;
}

void	ft_point_to_image(t_point point, t_mlx *mlx, int col, int legend)
{
	int		*addrs;
	int		size_line;
	int		pos;

	if (legend)
	{
		print_to_legend(point, mlx, col);
		return ;
	}
	if (point.x >= mlx->params->win_size.x || point.x < 0 ||
			point.y >= mlx->params->win_size.y || point.y < 0)
		return ;
	size_line = mlx->params->win_size.x;
	addrs = (int *)(mlx->addrs);
	pos = point.y * size_line + point.x;
	addrs[pos] = col;
}
