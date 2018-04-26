/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 04:06:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/26 05:22:49 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_resize(t_point p, int zoom)
{
	t_point vector;

	vector = ft_vprodbyscal(p, zoom / ft_vnorm(p));
	p = ft_vadd(p, vector);
	return (p);
}
