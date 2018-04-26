/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 00:34:23 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/26 05:42:48 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** if (!(mlx->params->filename))
** return(mlx_new_image(mlx->ptr, x, y));
*/

void	*ft_new_image(t_mlx *mlx, int x, int y)
{
	int width;
	int height;

	width = x;
	height = y;
	return (mlx_xpm_file_to_image(mlx->ptr, "dignidad.xpm", &width, &height));
}
