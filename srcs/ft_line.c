/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/18 04:46:20 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color(int *height, int max, int pos)
{
	if (!height)
		return (0xFFFFFF);
	else
		return (ft_get_color(height[0], height[1], max, pos));
}

void		ft_line(t_point *p, void *mlx, int h, int h2)
{
	t_point	dp;
	int		increments[4];
	int		numerator;
	int		i;
	t_point	tmp;

	dp = ft_newpoint(p[1].x - p[0].x, p[1].y - p[0].y, 0);
	increments[0] = dp.x < 0 ? -1 : 1;
	increments[1] = dp.y < 0 ? -1 : 1;
	dp = ft_newpoint(fabs(dp.x), fabs(dp.y), 0);
	increments[2] = dp.x <= dp.y ? 0 : increments[0];
	increments[3] = dp.x <= dp.y ? increments[1] : 0;
	dp = dp.x <= dp.y ? ft_newpoint(dp.y, dp.x, 0) : dp;
	numerator = (int)dp.x >> 1;
	i = 0;
	tmp = p[0];
	while (++i <= dp.x + 1)
	{
		ft_point_to_image(ft_newpoint(tmp.x, tmp.y, 0), mlx, ft_get_color(h, h2, dp.x + 1, i));
		numerator += dp.y;
		tmp.x += numerator >= dp.x ? increments[0] : increments[2];
		tmp.y += numerator >= dp.x ? increments[1] : increments[3];
		numerator -= numerator >= dp.x ? dp.x : 0;
	}
}
