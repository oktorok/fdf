/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:01:53 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/21 04:36:11 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point ft_vprodbyscal(t_point p, double n)
{
	return (ft_newpoint(p.x * n, p.y * n, p.z * n));
}

t_point ft_vadd(t_point p, t_point q)
{
	return (ft_newpoint(p.x + q.x, p.y + q.y, p.z + q.z));
}

t_point ft_vrest(t_point p, t_point q)
{
	return (ft_newpoint(p.x - q.x, p.y - q.y, p.z - q.z));
}
