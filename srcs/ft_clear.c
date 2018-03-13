/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:30:58 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/04 23:32:38 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear(void *mlx)
{
	t_mlx *my_mlx;

	my_mlx = (t_mlx *)mlx;
	mlx_clear_window(my_mlx->ptr, my_mlx->win);
	return ;
}
