/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cavaliere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 03:19:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/23 03:32:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cavaliere(t_point *v)
{
	double cosen;
	double sen;

	cosen = cos(45.0 / 180.0 * M_PI);
	sen = cos(45.0 / 180.0 * M_PI);
	v[0] = ft_newpoint(v[0].x + 0.5 * cosen * v[0].y, 0.5 * sen * v[0].y + v[0].z, 0);
	v[1] = ft_newpoint(v[1].x + 0.5 * cosen * v[1].y, 0.5 * sen * v[1].y + v[1].z, 0);
	v[2] = ft_newpoint(v[2].x + 0.5 * cosen * v[2].y, 0.5 * sen * v[0].y + v[2].z, 0);
}
