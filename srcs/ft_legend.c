/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 02:35:27 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/26 07:19:56 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "locale.h"

static int		check_angle(double *angle)
{
	if (*angle < 0)
		*angle += 360.0;
	else if (*angle > 360.0)
		*angle = (int)*angle % 360;
	return ((int)*angle);
}

static void		place_info(t_mlx *mlx, char *filename, char **info)
{
	mlx_string_put(mlx->ptr, mlx->win, 15, 30, 0xFFFFFF, "FILENAME:   ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 50, 0xFFFFFF, "ANGLE X:    ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 70, 0xFFFFFF, "ANGLE Y:    ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 90, 0xFFFFFF, "ANGLE Z:    ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 110, 0xFFFFFF, "ZOOM:       ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 130, 0xFFFFFF, "PROYECTION: ");
	mlx_string_put(mlx->ptr, mlx->win, 130, 30, 0xFFFFFF, filename);
	mlx_string_put(mlx->ptr, mlx->win, 130, 50, 0xFFFFFF, info[0]);
	free(info[0]);
	mlx_string_put(mlx->ptr, mlx->win, 130, 70, 0xFFFFFF, info[1]);
	free(info[1]);
	mlx_string_put(mlx->ptr, mlx->win, 130, 90, 0xFFFFFF, info[2]);
	free(info[2]);
	mlx_string_put(mlx->ptr, mlx->win, 130, 110, 0xFFFFFF, info[3]);
	free(info[3]);
	if (mlx->params->proyection == 0)
		mlx_string_put(mlx->ptr, mlx->win, 130, 130, 0xFFFFFF, "NONE");
	else if (mlx->params->proyection == 1)
		mlx_string_put(mlx->ptr, mlx->win, 130, 130, 0xFFFFFF, "ISOMETRIC");
	else if (mlx->params->proyection == 2)
		mlx_string_put(mlx->ptr, mlx->win, 130, 130, 0xFFFFFF, "CABINET");
	else if (mlx->params->proyection == 3)
		mlx_string_put(mlx->ptr, mlx->win, 130, 130, 0xFFFFFF, "CAVALIERE");
	else if (mlx->params->proyection == 4)
		mlx_string_put(mlx->ptr, mlx->win, 130, 130, 0xFFFFFF, "CONIC");
}

static void		place_keys(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 100, 150, 0xE72512, "KEYS");
	mlx_string_put(mlx->ptr, mlx->win, 15, 170, 0xFFFFFF, "RESET:     ");
	mlx_string_put(mlx->ptr, mlx->win, 150, 170, 0xFFFFFF, "DEL");
	mlx_string_put(mlx->ptr, mlx->win, 15, 190, 0xFFFFFF, "EXIT:      ");
	mlx_string_put(mlx->ptr, mlx->win, 150, 190, 0xFFFFFF, "ESC");
	mlx_string_put(mlx->ptr, mlx->win, 15, 210, 0xFFFFFF, "MOVEMENT:");
	mlx_string_put(mlx->ptr, mlx->win, 150, 210, 0xFFFFFF, "ARROWS");
	mlx_string_put(mlx->ptr, mlx->win, 100, 230, 0xE72512, "TURN KEYS");
	mlx_string_put(mlx->ptr, mlx->win, 15, 250, 0xFFFFFF, "X+ / X-: ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 270, 0xFFFFFF, "Y+ / Y-: ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 290, 0xFFFFFF, "Z+ / Z-: ");
	mlx_string_put(mlx->ptr, mlx->win, 150, 250, 0xFFFFFF, "8 / 5 NUM_PADS");
	mlx_string_put(mlx->ptr, mlx->win, 150, 270, 0xFFFFFF, "6 / 4 NUM_PADS");
	mlx_string_put(mlx->ptr, mlx->win, 150, 290, 0xFFFFFF, "9 / 7 NUM_PADS");
	mlx_string_put(mlx->ptr, mlx->win, 100, 310, 0xE72512, "PROYECTION KEYS");
	mlx_string_put(mlx->ptr, mlx->win, 15, 330, 0xFFFFFF, "ISOMETRIC: ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 350, 0xFFFFFF, "CABINET:   ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 370, 0xFFFFFF, "CAVALIERE: ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 390, 0xFFFFFF, "CONIC:     ");
	mlx_string_put(mlx->ptr, mlx->win, 150, 330, 0xFFFFFF, "Q");
	mlx_string_put(mlx->ptr, mlx->win, 150, 350, 0xFFFFFF, "W");
	mlx_string_put(mlx->ptr, mlx->win, 150, 370, 0xFFFFFF, "E");
	mlx_string_put(mlx->ptr, mlx->win, 150, 390, 0xFFFFFF, "R");
}

void			ft_legend(t_mlx *mlx)
{
	char	*filename;
	char	**info;

	filename = ft_strrchr(mlx->params->filename, '/') + 1;
	mlx_string_put(mlx->ptr, mlx->win, 100, 10, 0xE72512, "DATA");
	info = (char **)malloc(sizeof(char *) * 4);
	info[0] = ft_itoa(check_angle(&mlx->params->rotated.x));
	info[1] = ft_itoa(check_angle(&mlx->params->rotated.y));
	info[2] = ft_itoa(check_angle(&mlx->params->rotated.z));
	info[3] = ft_itoa((int)mlx->params->zoomed);
	place_info(mlx, filename, info);
	free(info);
	place_keys(mlx);
}
