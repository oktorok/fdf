/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 02:43:56 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/24 03:44:20 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(t_point *v)
{
	v[0] = ft_newpoint(M_SQRT2 / 2 * v[0].x + -M_SQRT2 / 2 * v[0].y,
			-1 / sqrt(6) * v[0].x + -1 / sqrt(6) * v[0].y + sqrt(2 / 3) * v[0].z
			, 0);
	v[1] = ft_newpoint(M_SQRT2 / 2 * v[1].x + -M_SQRT2 / 2 * v[1].y,
			-1 / sqrt(6) * v[1].x + -1 / sqrt(6) * v[1].y + sqrt(2 / 3) * v[1].z
			, 0);
	v[2] = ft_newpoint(M_SQRT2 / 2 * v[2].x + -M_SQRT2 / 2 * v[2].y,
			-1 / sqrt(6) * v[2].x + -1 / sqrt(6) * v[2].y + sqrt(2 / 3) * v[2].z
			, 0);
}
