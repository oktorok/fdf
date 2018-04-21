/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:05:42 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/21 04:43:05 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point ft_newpoint(double x, double y, double z)
{
	t_point p;
	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}
