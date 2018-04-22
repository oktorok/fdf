/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 04:06:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/22 04:19:06 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point ft_resize(t_point p, int zoom)
{
	t_point vector;
	double	norm;

	norm = ft_vnorm(p);
	vector = ft_vprodbyscal(p, zoom / norm);
	p = ft_vadd(p, vector);
	return (p);
}
