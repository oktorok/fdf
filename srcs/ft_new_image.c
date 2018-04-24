/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:34:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/24 06:25:54 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_new_image(void *mlx)
{
	t_mlx *tmpmlx;

	tmpmlx = (t_mlx *)mlx;
	return (mlx_new_image(tmpmlx->ptr, tmpmlx->params->win_size.x,
				tmpmlx->params->win_size.y));
}
