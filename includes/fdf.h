/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 06:18:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/06 03:56:26 by jagarcia         ###   ########.fr       */
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
/*
 *COLOR CONF
 */
#define DEEP_VALUE -15
#define NORMAL_VALUE 0
#define HIGH_VALUE 15
#define COLOR_DEEP 0x0000FF
#define COLOR_HIGH 0xFF0000
#define COLOR_SCALE 1020 / (HIGH_VALUE-DEEP_VALUE + 1)

/*
 *COLOR CONF
 */
/*
 * KEYS
 */
#define KEY_RELEASE_EVENT 2
#define KEY_RELEASE_MASK (1L<<0)
#define UP_ARROW 65362 /*125*/
#define LEFT_ARROW 65361 /*123*/
#define RIGHT_ARROW 65363 /*124*/
#define DOWN_ARROW 65364 /*126*/
#define ESCAPE 65307 /*53*/
#define ZOOM_IN 122
#define ZOOM_OUT 120
#define TURN_1 119
#define TURN_2 113
/*
 * KEYS
 */
#define BUFFER_INT 1000
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
typedef struct s_params
{
	t_point		win_size;
	t_point		true_origen;
	t_point		vector_z;
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
void		ft_line(t_point *p, void *mlx, int h, int h2);
t_point 	ft_newpoint(int x, int y);
void		*ft_open_window(t_mlx *mlx);
int			ft_draw(void *mlx);
int			ft_mouse_draw(int x, int y, void *mlx);
int			ft_wall(void *mlx, int color);
void		ft_point(t_point point, void *mlx, int color);
void		ft_circle(int x, int y, void *mlx, int color);
int			*ft_lector(char *filename);
double		ft_pendant(t_point p1, t_point p2);
int			ft_equline(t_point point, double pendant, int x, char inv);
t_point		ft_rotatepoint(t_point point, t_point origin, int grades);
void		ft_clear(void *mlx);
t_params	*ft_iniparams(int *pixel);
void		ft_coder(void *mlx, int code);
int			ft_get_color(int h, int h2, int cuant, int num);
#endif
