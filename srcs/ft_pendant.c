/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pendant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:32:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/18 08:42:17 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_pendant(t_point p1, t_point p2)
{
	double	dif_y;
	double	dif_x;
	double	res;

	dif_y = (double)p2.y - (double)p1.y;
	dif_x = (double)p2.x - (double)p1.x;
	res = (double)dif_y / (double)dif_x;
	return (res);
}
