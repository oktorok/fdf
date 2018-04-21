/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:33:16 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/21 05:14:08 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_coder(void *mlx, int code)
{
	t_params	*params;
	t_point		*vector;

	vector = ((t_mlx *)mlx)->vector;
	params = ((t_mlx *)mlx)->params;
	if (code == LEFT_ARROW)
		params->true_origen.x -= MOVE;
	else if (code == UP_ARROW)
		params->true_origen.y += MOVE;
	else if (code == RIGHT_ARROW)
		params->true_origen.x += MOVE;
	else if (code == DOWN_ARROW)
		params->true_origen.y -= MOVE;
	else if (code == ZOOM_OUT)
//		params->cube_side -= ZOOM_CUANT;
	{
	vector[0] = ft_vprodbyscal(vector[0], 1/ZOOM_CUANT);
    vector[1] = ft_vprodbyscal(vector[1], 1/ZOOM_CUANT);
    vector[2] = ft_vprodbyscal(vector[2], 1/ZOOM_CUANT);
	}
	if (code == ZOOM_IN)
	{
	vector[0] = ft_vprodbyscal(vector[0], ZOOM_CUANT);
    vector[1] = ft_vprodbyscal(vector[1], ZOOM_CUANT);
    vector[2] = ft_vprodbyscal(vector[2], ZOOM_CUANT);
	}
	else if (code == TURN_1_X)
	{
		vector[1] = ft_rotator(vector[1], -ROT, vector[0]);
		vector[2] = ft_rotator(vector[2], -ROT, vector[0]);
	}	
	else if (code == TURN_2_X)
	{
		vector[1] = ft_rotator(vector[1], ROT, vector[0]);
		vector[2] = ft_rotator(vector[2], ROT, vector[0]);
	}
	else if (code == TURN_1_Y)
	{
		vector[0] = ft_rotator(vector[0], -ROT, vector[1]);
		vector[2] = ft_rotator(vector[2], -ROT, vector[1]);
	}
	else if (code == TURN_2_Y)
	{
		vector[0] = ft_rotator(vector[0], ROT, vector[1]);
		vector[2] = ft_rotator(vector[2], ROT, vector[1]);
	}
	else if (code == TURN_1_Z)
	{
		vector[0] = ft_rotator(vector[0], -ROT, vector[2]);
		vector[1] = ft_rotator(vector[1], -ROT, vector[2]);
	}
	else if (code == TURN_2_Z)
	{
		vector[0] = ft_rotator(vector[0], ROT, vector[2]);
		vector[1] = ft_rotator(vector[1], ROT, vector[2]);
	}
	else if (code == ISOMETRIC)
		vector = ft_isometric(vector);
//	else if (code == 9)
	else if (code == RESET)
		((t_mlx *)mlx)->params = ft_initialize(((t_mlx *)mlx)->pixel, ((t_mlx *)mlx)->vector);
	else
		return ;
	ft_print_image(mlx);
}
