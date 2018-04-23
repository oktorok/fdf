/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cabinet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:29:59 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/23 02:41:44 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	ft_cabinet(t_point *v)
{
	double sen; 
	double cosen;

	cosen = cos((63.4 / 180.0) * M_PI);
	sen = sin((63.4 / 180.0) * M_PI);
	v[0] = ft_newpoint(v[0].x + (1.0 / 2.0) * v[0].z * cosen, v[0].y + (1.0 / 2.0) * v[0].z * sen, 0);
	v[1] = ft_newpoint(v[1].x + (1.0 / 2.0) * v[1].z * cosen, v[1].y + (1.0 / 2.0) * v[1].z * sen, 0);
	v[2] = ft_newpoint(v[2].x + (1.0 / 2.0) * v[2].z * cosen, v[2].y + (1.0 / 2.0) * v[2].z * sen, 0);
}
