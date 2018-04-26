/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:25:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/26 05:50:57 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_initialize(t_point *vector, t_params **params)
{
	if (!*params)
		if (!(*params = (t_params *)ft_memalloc(sizeof(t_params))))
			ft_error(NULL);
	(*params)->win_size = ft_newpoint(1920, 1080, 0.0);
	(*params)->true_origen = ft_newpoint((*params)->win_size.x / 2,
							(*params)->win_size.y / 2, 0.0);
	(*params)->proyection = 0;
	(*params)->rotated = ft_newpoint(0, 0, 0);
	(*params)->zoomed = 10;
	vector[0] = ft_resize(ft_newpoint(1, 0, 0), 10);
	vector[1] = ft_resize(ft_newpoint(0, 1, 0), 10);
	vector[2] = ft_resize(ft_newpoint(0, 0, -1), 10);
}
