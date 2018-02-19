/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 06:18:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/19 20:18:49 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

void	ft_draw_line(t_point p1, t_point p2, void *mlx);
t_point ft_newpoint(double x, double y);
void	*ft_open_window(void *mlx, size_t x, size_t y, char *title);
int		ft_draw(void *mlx, int code);
int		ft_mouse_draw(int x, int y, void *mlx);
int		ft_wall(void *mlx, int color);
#endif
