/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 06:18:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/23 03:49:37 by jagarcia         ###   ########.fr       */
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
#define DEEP_VALUE -5
#define HIGH_VALUE 10
#define COLOR_DEEP 0x0000FF
#define COLOR_HIGH 0xFF0000
#define COLOR_SCALE 1020 / (HIGH_VALUE-DEEP_VALUE + 1)
/*
 *COLOR CONF
 */
/*
 *MOVE CONF
 */
#define ROT 10
#define ZOOM_CUANT 5
#define MOVE 10
/*
 *MOVE CONF
 */

/*
 * KEYS
 */
#ifdef __APPLE__
#define KEY_RELEASE_EVENT 2
#define KEY_RELEASE_MASK 1
#define UP_ARROW /*65362*/ 125
#define LEFT_ARROW /*65361*/ 123
#define RIGHT_ARROW /*65363*/ 124
#define DOWN_ARROW /*65364*/ 126
#define ESCAPE /*65307*/ 53
#define ZOOM_IN /*122*/ 69
#define ZOOM_OUT /*120*/ 78
#define TURN_1_X 84
#define TURN_2_X 91
#define TURN_1_Y 86
#define TURN_2_Y 88
#define TURN_1_Z 89
#define TURN_2_Z 92
#define RESET 51
#define ISOMETRIC 12
#else
#define KEY_RELEASE_EVENT 2
#define KEY_RELEASE_MASK 1
#define UP_ARROW 65362
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define DOWN_ARROW 65364
#define ESCAPE 65307
#define ZOOM_IN 65451
#define ZOOM_OUT 65453
#define TURN_1_X 65431
#define TURN_2_X 65437
#define TURN_1_Y 65432
#define TURN_2_Y 65430
#define TURN_1_Z 65429
#define TURN_2_Z 65434
#define RESET 65288
#define ISOMETRIC 113
#define CABINET 119
#define CAVALIERE 101
#define CONIC 114
#endif
/*
 * KEYS
 */
#define BITS_PER_PIXEL 32
#define ENDIAN 0
#define BUFFER_INT 1000
typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
}				t_point;
typedef struct s_params
{
	t_point		win_size;
	t_point		true_origen;
	int			proyection;
}				t_params;
typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addrs;
	t_params	*params;
	int			*pixel;
	t_point		vector[3];
}				t_mlx;
t_point		ft_resize(t_point p, int zoom);
t_point		ft_vprodbyscal(t_point p, double n);
t_point		ft_vadd(t_point p, t_point q);
t_point		ft_vrest(t_point p, t_point q);
t_point		ft_vset(t_point *sr, int x, int y, int z);
double		ft_vnorm(t_point p);
void		ft_line(t_point *p, void *mlx, int h, int h2);
t_point 	ft_newpoint(double x, double y, double z);
void		*ft_open_window(t_mlx *mlx);
int			ft_draw(void *mlx);
void		ft_point_to_image(t_point point, void *mlx, int color);
int			*ft_lector(char *filename);
void		ft_clear(void *mlx);
void		ft_initialize(int *pixel, t_point vector[3], t_params **params);
void		ft_coder(void *mlx, int code);
int			ft_get_color(int h, int h2, int cuant, int num);
void		*ft_new_image(void *mlx);
char		*ft_image_addrs(void *mlx);
int			ft_print_image(void *mlx);
int			ft_destroy_image(void *mlx);
t_point		ft_rotator(t_point rot_pnt, int angle, t_point rot_axi);
void		ft_isometric(t_point *v);
void		ft_cavaliere(t_point *v);
void		ft_cabinet(t_point *v);
void		ft_conic(t_point *v);
#endif
