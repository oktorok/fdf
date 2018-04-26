/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:34:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/26 08:16:04 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_new_image(t_mlx *mlx, int x, int y)
{
	int width;
	int height;

	if (!(mlx->params->image_name))
		return (mlx_new_image(mlx->ptr, x, y));
	return (mlx_xpm_file_to_image(mlx->ptr, mlx->params->image_name,
				&width, &height));
}
