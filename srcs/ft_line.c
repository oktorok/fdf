/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/13 22:19:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_line(t_point *p, void *mlx, int h, int h2)
{
	t_point	dp;
	int		increments[4];
	int		numerator;
	int		i;
	int		cuant;

	dp = ft_newpoint(p[1].x - p[0].x, p[1].y - p[0].y);
	increments[0] = dp.x < 0 ? -1 : 1;
	increments[1] = dp.y < 0 ? -1 : 1;
	dp = ft_newpoint(labs(dp.x), labs(dp.y));
	increments[2] = dp.x <= dp.y ? 0 : increments[0];
	increments[3] = dp.x <= dp.y ? increments[1] : 0;
	dp = dp.x <= dp.y ? ft_newpoint(dp.y, dp.x) : dp;
	numerator = dp.x >> 1;
	cuant = dp.x + 1;
	i = 0;
	while (++i <= dp.x + 1)
	{
		ft_point(ft_newpoint(p[0].x, p[0].y), mlx,
				ft_get_color(h, h2, dp.x + 1, i));
		numerator += dp.y;
		p[0].x += numerator >= dp.x ? increments[0] : increments[2];
		p[0].y += numerator >= dp.x ? increments[1] : increments[3];
		numerator -= numerator >= dp.x ? dp.x : 0;
	}
}
