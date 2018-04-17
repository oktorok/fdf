/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_addrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:44:00 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/15 01:00:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_image_addrs(void *mlx)
{
	t_mlx	*tmpmlx;
	int		bpp;
	int		endian;
	int		size_line;

	bpp = BITS_PER_PIXEL;
	size_line = tmpmlx->params->win_size.x;
	endian = ENDIAN;
	tmpmlx = (t_mlx *)mlx;
	return (mlx_get_data_addr(tmpmlx->img, &bpp, &size_line, &endian));
}
