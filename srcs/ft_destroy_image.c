/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:57:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/21 01:52:14 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_image(void *mlx)
{
	t_mlx *mymlx;
	mymlx = ((t_mlx *)mlx);
	mlx_destroy_image(mymlx->ptr, mymlx->img);
}
