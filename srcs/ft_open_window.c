/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 06:14:06 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/15 00:32:07 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_open_window(t_mlx *mlx)
{
	return (mlx_new_window(mlx->ptr, mlx->params->win_size.x,
				mlx->params->win_size.y, "FdF"));
}
