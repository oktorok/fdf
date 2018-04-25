/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:57:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 07:30:26 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	swap(t_point *tmp, int *h, int *h2, t_point *p)
{
	int		tmph;

	if (*h > *h2)
	{
		*tmp = ft_newpoint((int)p[1].x, (int)p[1].y, (int)p[1].z);
		tmph = *h;
		*h = *h2;
		*h2 = tmph;
		return (ft_newpoint((int)(p[0].x - p[1].x), (int)(p[0].y - p[1].y), 0));
	}
	*tmp = ft_newpoint((int)p[0].x, (int)p[0].y, (int)p[0].z);
	return (ft_newpoint((int)(p[1].x - p[0].x), (int)(p[1].y - p[0].y), 0));
}

void			ft_line(t_point *p, t_mlx *mlx, int h, int h2)
{
	t_point	dp;
	int		increments[4];
	int		numerator;
	int		i;
	t_point	tmp;

	dp = swap(&tmp, &h, &h2, p);
	increments[0] = dp.x < 0 ? -1 : 1;
	increments[1] = dp.y < 0 ? -1 : 1;
	dp = ft_newpoint(fabs(dp.x), fabs(dp.y), 0);
	increments[2] = dp.x <= dp.y ? 0 : increments[0];
	increments[3] = dp.x <= dp.y ? increments[1] : 0;
	dp = dp.x <= dp.y ? ft_newpoint(dp.y, dp.x, 0) : dp;
	numerator = (int)dp.x >> 1;
	i = 0;
	while (++i <= dp.x + 1)
	{
		ft_point_to_image(ft_newpoint(tmp.x, tmp.y, 0), mlx,
				ft_get_color(h, h2, dp.x + 1, i));
		numerator += dp.y;
		tmp.x += numerator >= dp.x ? increments[0] : increments[2];
		tmp.y += numerator >= dp.x ? increments[1] : increments[3];
		numerator -= numerator >= dp.x ? dp.x : 0;
	}
}
