/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 03:43:29 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/24 00:49:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_conic(t_point *v)
{
	double dist_plane;
	double dist_object;

	dist_plane = 1000.0;
	dist_object = 2000.0;
	if (v[0].z > dist_object)
		dist_object = v[0].z + 1;
	v[0] = ft_newpoint(dist_plane * v[0].x / (dist_object - v[0].z),
			dist_plane * v[0].y / (dist_object - v[0].z), 0);
}
