/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 06:18:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/26 19:57:21 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <mlx.h>
#include <errno.h>
#define PONT_SIZE 2
typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			*pixel;
}				t_mlx;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	ft_draw_line(t_point p1, t_point p2, void *mlx);
t_point ft_newpoint(int x, int y);
void	*ft_open_window(t_mlx *mlx);
int		ft_draw(void *mlx, int code);
int		ft_mouse_draw(int x, int y, void *mlx);
int		ft_wall(void *mlx, int color);
void	ft_point(int x, int y, void *mlx, int color);
void	ft_circle(int x, int y, void *mlx, int color);
int		*ft_lector(char *filename);
#endif
