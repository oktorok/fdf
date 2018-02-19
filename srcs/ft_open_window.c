/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 06:14:06 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 15:38:22 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_open_window(void *ptr_mlx, size_t x, size_t y, char *title)
{
	void	*win_mlx;

	win_mlx = mlx_new_window(ptr_mlx, x, y, title);
	return (win_mlx);
}
