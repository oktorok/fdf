/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 01:22:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 00:46:13 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_print_image(t_mlx *mlx, void *img)
{
	return (mlx_put_image_to_window(mlx->ptr, mlx->win, img, 0, 0));
}
