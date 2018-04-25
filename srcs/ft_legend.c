/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 02:35:27 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 05:51:15 by jagarcia         ###   ########.fr       */
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

static void		place_info(t_mlx *mlx, char *filename)
{
	mlx_string_put(mlx->ptr, mlx->win, 15, 30, 0xFFFFFF, "FILENAME:   ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 50, 0xFFFFFF, "ANGLE X:    ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 70, 0xFFFFFF, "ANGLE Y:    ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 90, 0xFFFFFF, "ANGLE Z:    ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 110, 0xFFFFFF, "ZOOM:       ");
	mlx_string_put(mlx->ptr, mlx->win, 15, 130, 0xFFFFFF, "PROYECTION: ");
	mlx_string_put(mlx->ptr, mlx->win, 130, 30, 0xFFFFFF, filename);
	mlx_string_put(mlx->ptr, mlx->win, 130, 50, 0xFFFFFF,
			ft_itoa(check_angle(&mlx->params->rotated.x)));
	mlx_string_put(mlx->ptr, mlx->win, 130, 70, 0xFFFFFF,
			ft_itoa(check_angle(&mlx->params->rotated.y)));
	mlx_string_put(mlx->ptr, mlx->win, 130, 90, 0xFFFFFF,
			ft_itoa(check_angle(&mlx->params->rotated.z)));
	mlx_string_put(mlx->ptr, mlx->win, 130, 110, 0xFFFFFF,
			ft_itoa((int)mlx->params->zoomed));
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

static void		wall(t_mlx *mlx, int x, int y)
{
	int	*addrs_leg;
	int *addrs;
	int line_size;
	int	i;

	i = 0;
	line_size = (int)mlx->params->win_size.x;
	addrs_leg = (int *)mlx->addrs_leg;
	addrs = (int *)mlx->addrs;
	while (i < x * y)
	{
		addrs_leg[i] = addrs[(i % x) + i / x * line_size];
		i++;
	}
}

void			ft_legend(t_mlx *mlx)
{
	char	*filename;

	if (!(mlx->img_leg = ft_new_image(mlx, LEG_X, LEG_Y)))
		ft_error(NULL);
	mlx->addrs_leg = ft_image_addrs(mlx->img_leg, LEG_X);
	wall(mlx, LEG_X, LEG_Y);
	ft_print_image(mlx, mlx->img_leg);
	filename = ft_strrchr(mlx->params->filename, '/') + 1;
	mlx_string_put(mlx->ptr, mlx->win, 100, 10, 0xE72512, "DATA");
	place_info(mlx, filename);
	place_keys(mlx);
}