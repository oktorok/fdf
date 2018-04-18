/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:33:16 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/18 04:56:49 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int check_angle(int angle)
{
	if (angle < 0)
		return (360 + angle);
	else if (angle >= 360)
		return (angle - 360);
	return (angle);
}

void	ft_coder(void *mlx, int code)
{
	t_params *params;

	params = ((t_mlx *)mlx)->params;
	if (code == LEFT_ARROW)
		params->true_origen.x -= 10;
	else if (code == UP_ARROW)
		params->true_origen.y += 10;
	else if (code == RIGHT_ARROW)
		params->true_origen.x += 10;
	else if (code == DOWN_ARROW)
		params->true_origen.y -= 10;
	else if (code == ZOOM_OUT)
	{
		params->cube_side.x -= 5;
		params->cube_side.y -= 5;
		params->cube_side.z -= 5;
	}
	else if (code == ZOOM_IN)
	{
		params->cube_side.x += 5;
		params->cube_side.y += 5;
		params->cube_side.z += 5;
	}
//	else if (code == TURN_1)
//	else if (code == TURN_2)
	else if (code == 14)
		params->angle.x -= 10;
	else if (code == 15)
		params->angle.x += 10;
	else if (code == 2)
		params->angle.y -= 10;
	else if (code == 3)
		params->angle.y += 10;
	else if (code == 0)
		params->angle.z -= 10;
	else if (code == 1)
		params->angle.z += 10;
//	else if (code == 8)
//	else if (code == 9)
	else if (code == 51)
		((t_mlx *)mlx)->params = ft_initialize(((t_mlx *)mlx)->pixel, ((t_mlx *)mlx)->vector);
	else
		return ;
	ft_clear(mlx);
}
