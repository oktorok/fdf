/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:33:16 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 08:27:55 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom_move(int code, t_point *vector, t_params *params)
{
	if (code == LEFT_ARROW)
		params->true_origen.x -= MOVE;
	else if (code == UP_ARROW)
		params->true_origen.y += MOVE;
	else if (code == RIGHT_ARROW)
		params->true_origen.x += MOVE;
	else if (code == DOWN_ARROW)
		params->true_origen.y -= MOVE;
	else if (code == ZOOM_OUT)
	{
		params->zoomed -= ZOOM_CUANT;
		vector[0] = ft_resize(vector[0], -ZOOM_CUANT);
		vector[1] = ft_resize(vector[1], -ZOOM_CUANT);
		vector[2] = ft_resize(vector[2], -ZOOM_CUANT);
	}
	else if (code == ZOOM_IN)
	{
		params->zoomed += ZOOM_CUANT;
		vector[0] = ft_resize(vector[0], ZOOM_CUANT);
		vector[1] = ft_resize(vector[1], ZOOM_CUANT);
		vector[2] = ft_resize(vector[2], ZOOM_CUANT);
	}
}

static void		turn_1(int code, t_point *vector, t_params *params)
{
	if (code == TURN_1_X)
	{
		params->rotated.x -= ROT;
		vector[1] = ft_rotator(vector[1], -ROT, vector[0]);
		vector[2] = ft_rotator(vector[2], -ROT, vector[0]);
	}
	else if (code == TURN_1_Y)
	{
		params->rotated.y -= ROT;
		vector[0] = ft_rotator(vector[0], -ROT, vector[1]);
		vector[2] = ft_rotator(vector[2], -ROT, vector[1]);
	}
	else if (code == TURN_1_Z)
	{
		params->rotated.z -= ROT;
		vector[0] = ft_rotator(vector[0], -ROT, vector[2]);
		vector[1] = ft_rotator(vector[1], -ROT, vector[2]);
	}
}

static void		turn_2(int code, t_point *vector, t_params *params)
{
	if (code == TURN_2_X)
	{
		params->rotated.x += ROT;
		vector[1] = ft_rotator(vector[1], ROT, vector[0]);
		vector[2] = ft_rotator(vector[2], ROT, vector[0]);
	}
	else if (code == TURN_2_Y)
	{
		params->rotated.y += ROT;
		vector[0] = ft_rotator(vector[0], ROT, vector[1]);
		vector[2] = ft_rotator(vector[2], ROT, vector[1]);
	}
	else if (code == TURN_2_Z)
	{
		params->rotated.z += ROT;
		vector[0] = ft_rotator(vector[0], ROT, vector[2]);
		vector[1] = ft_rotator(vector[1], ROT, vector[2]);
	}
}

static void		proyection(int code, t_params *params, t_mlx *mlx)
{
	if (code == ISOMETRIC)
	{
		ft_initialize(mlx->pixel, ((t_mlx *)mlx)->vector, &params);
		params->proyection = 1;
	}
	else if (code == CABINET)
	{
		ft_initialize(mlx->pixel, ((t_mlx *)mlx)->vector, &params);
		params->proyection = 2;
	}
	else if (code == CAVALIERE)
	{
		ft_initialize(mlx->pixel, ((t_mlx *)mlx)->vector, &params);
		params->proyection = 3;
	}
	else if (code == CONIC)
	{
		ft_initialize(mlx->pixel, ((t_mlx *)mlx)->vector, &params);
		params->proyection = 4;
	}
}

void			ft_coder(t_mlx *mlx, int code)
{
	t_params	*params;
	t_point		*vector;

	vector = mlx->vector;
	params = mlx->params;
	if (code == LEFT_ARROW || code == UP_ARROW || code == DOWN_ARROW ||
			code == RIGHT_ARROW || code == ZOOM_OUT || code == ZOOM_IN)
		zoom_move(code, vector, params);
	else if (code == TURN_1_X || code == TURN_1_Y || code == TURN_1_Z)
		turn_1(code, vector, params);
	else if (code == TURN_2_X || code == TURN_2_Y || code == TURN_2_Z)
		turn_2(code, vector, params);
	else if (code == ISOMETRIC || code == CABINET || code == CAVALIERE ||
			code == CONIC)
		proyection(code, params, mlx);
	else if (code == RESET)
		ft_initialize(((t_mlx *)mlx)->pixel, ((t_mlx *)mlx)->vector, &params);
	else
		return ;
	if (mlx->img)
		ft_destroy_image(mlx, mlx->img);
}
