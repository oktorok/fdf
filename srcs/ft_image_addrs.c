/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_addrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:44:00 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 00:38:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_image_addrs(void *img, int size_line)
{
	int		bpp;
	int		endian;

	bpp = BITS_PER_PIXEL;
	endian = ENDIAN;
	return (mlx_get_data_addr(img, &bpp, &size_line, &endian));
}
