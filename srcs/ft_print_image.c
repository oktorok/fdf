/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 01:22:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/21 00:57:28 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_print_image(void *mlx)
{
	t_mlx *tmpmlx;

	tmpmlx = (t_mlx *)mlx;
	return (mlx_put_image_to_window(tmpmlx->ptr, tmpmlx->win, tmpmlx->img, 0, 0));
}
