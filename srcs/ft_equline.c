/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 21:01:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/06 03:59:32 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_equline(t_point point, double pendant, int x, char inv)
{
	int y;

	if (!inv)
		return (point.y + pendant * (x - point.x));
	else
		return (((x - point.y) / pendant) + point.x);
}
