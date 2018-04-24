/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:01:53 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/24 03:31:14 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ft_vprodbyscal(t_point p, double n)
{
	return (ft_newpoint(p.x * n, p.y * n, p.z * n));
}

t_point		ft_vadd(t_point p, t_point q)
{
	return (ft_newpoint(p.x + q.x, p.y + q.y, p.z + q.z));
}

t_point		ft_vrest(t_point p, t_point q)
{
	return (ft_newpoint(p.x - q.x, p.y - q.y, p.z - q.z));
}

t_point		ft_vset(t_point *sist_ref, int x, int y, int z)
{
	t_point	x_pos;
	t_point	y_pos;
	t_point	z_pos;

	x_pos = ft_vprodbyscal(sist_ref[0], x);
	y_pos = ft_vprodbyscal(sist_ref[1], y);
	z_pos = ft_vprodbyscal(sist_ref[2], z);
	return (ft_vadd(ft_vadd(x_pos, y_pos), z_pos));
}

double		ft_vnorm(t_point p)
{
	return (sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2)));
}
