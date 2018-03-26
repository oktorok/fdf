/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 06:18:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/26 06:25:52 by jagarcia         ###   ########.fr       */
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
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct s_params
{
	t_point		win_size;
	t_point		true_origen;
	int			square_side;
	int			angle[2];
	int			turn;
	int			height;
}				t_params;
typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_params	*params;
	int			*pixel;
}				t_mlx;
void		ft_line(t_point p1, t_point p2, void *mlx);
t_point 	ft_newpoint(int x, int y);
void		*ft_open_window(t_mlx *mlx);
int			ft_draw(void *mlx);
int			ft_mouse_draw(int x, int y, void *mlx);
int			ft_wall(void *mlx, int color);
void		ft_point(t_point point, void *mlx, int color);
void		ft_circle(int x, int y, void *mlx, int color);
int			*ft_lector(char *filename);
double		ft_pendant(t_point p1, t_point p2);
int			ft_equline(t_point point, double pendant, int x);
t_point		ft_rotatepoint(t_point point, t_point origin, int grades);
void		ft_clear(void *mlx);
t_params	*ft_iniparams(int *pixel);
void		ft_coder(void *mlx, int code);
#endif
