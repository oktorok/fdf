/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:34:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 08:14:20 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_new_image(t_mlx *mlx, int x, int y)
{
	int width;
	int height;

	width = 1920;
	height = 1080;
	return (mlx_xpm_file_to_image(mlx->ptr, "dignidad.xpm", &width, &height));
}
