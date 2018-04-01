/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 23:33:16 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/30 22:54:00 by jagarcia         ###   ########.fr       */
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
    else if (code == 12)
        params->square_side -= 5;
    else if (code == 13)
        params->square_side += 5;
    else if (code == 6)
		params->turn = check_angle(params->turn + 10);
    else if (code == 7)
		params->turn = check_angle(params->turn - 10);
	else if (code == 14)
		params->angle[0] = check_angle(params->angle[0] - 10);
	else if (code == 15)
		params->angle[0] = check_angle(params->angle[0] + 10);
	else if (code == 2)
        params->angle[1] = check_angle(params->angle[1] - 10);
	else if (code == 3)
        params->angle[1] = check_angle(params->angle[1] + 10);
	else if (code == 8)
        params->height += 10;
	else if (code == 9)
        params->height -= 10;
	else if (code == 51)
		((t_mlx *)mlx)->params = ft_iniparams(((t_mlx *)mlx)->pixel);
	else
		return ;
	ft_clear(mlx);
}
