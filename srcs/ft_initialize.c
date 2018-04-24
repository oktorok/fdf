/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:25:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/23 21:57:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_initialize(int *pixel, t_point *vector, t_params **params)
{
	if (!*params)
		*params = (t_params *)ft_memalloc(sizeof(t_params));
	(*params)->win_size = ft_newpoint(1000, 1000, 0.0);
	(*params)->true_origen = ft_newpoint((*params)->win_size.x / 2,
							(*params)->win_size.x / 2, 0.0);
	(*params)->proyection = 0;
	vector[0] = ft_newpoint(1, 0, 0);
	vector[1] = ft_newpoint(0, 1, 0);
	vector[2] = ft_newpoint(0, 0, 1);
}
