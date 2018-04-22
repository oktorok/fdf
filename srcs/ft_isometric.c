/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 02:43:56 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/22 04:58:25 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_isometric(t_point *v)
{
	t_point *tmp;
	t_point *a;

	tmp = (t_point *)ft_memalloc(sizeof(t_point) * 3);
	tmp[0] = ft_vrest(ft_vprodbyscal(v[0], -M_SQRT2 / 2.0), ft_vprodbyscal(v[1], 1.0 / -sqrt(6.0)));
	tmp[1] = ft_vadd(ft_vprodbyscal(v[0], M_SQRT2 / 2.0), ft_vprodbyscal(v[1], - 1.0 / -sqrt(6.0)));
	tmp[2] = ft_vprodbyscal(v[1], -sqrt(2.0 / 3.0));

//	v[0] = tmp[0];
//	v[1] = tmp[1];
//	v[2] = tmp[2];
	return (tmp);
}
