/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iniparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:25:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/17 03:09:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_params	*ft_iniparams(int *pixel)
{
	t_params	*params;

	params = (t_params *)ft_memalloc(sizeof(t_params));
	params->win_size = ft_newpoint(1000.0, 1000.0, 0.0);
	params->true_origen = ft_newpoint(params->win_size.x / 2,
			params->win_size.x / 2, 0.0);
	params->square_side = 40;
	params->angle[0] = 0;
	params->angle[1] = 0;
	params->angle[2] = 0;
	params->turn = 0;
	params->height = 7;
	return (params);
}
