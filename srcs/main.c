/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 05:17:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/25 01:21:17 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_event(int code, void *mlx)
{
	t_mlx *mymlx;

	mymlx = (t_mlx *)mlx;
	if (code == ESCAPE)
	{
		ft_destroy_image(mymlx, mymlx->img_leg);
		ft_destroy_image(mymlx, mymlx->img);
		mlx_destroy_window(mymlx->ptr, mymlx->win);
		free(mymlx->params);
		free(mymlx->pixel);
		free(mymlx);
		exit(1);
	}
	ft_coder(mymlx, code);
	if (!(mymlx->img = ft_new_image(mymlx, mymlx->params->win_size.x, mymlx->params->win_size.y)))
		ft_error(NULL);
	if (!(mymlx->img_leg = ft_new_image(mymlx, 100, 100)))
		ft_error(NULL);
	mymlx->addrs_leg = ft_image_addrs(mymlx->img_leg, 100);
	mymlx->addrs = ft_image_addrs(mymlx->img, mymlx->params->win_size.x);
	ft_draw(mymlx);
//	ft_legend(mymlx);
	ft_print_image(mymlx, mymlx->img);
	ft_print_image(mymlx, mymlx->img_leg);
	return (0);
}

int			main(int argn, char **argv)
{
	t_mlx		*mlx;

	if (argn != 2)
	{
		ft_printf("Usage: fdf file_path\n");
		return (-1);
	}
	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_error(NULL);
	mlx->pixel = ft_lector(argv[1]);
	ft_initialize(mlx->pixel, mlx->vector, &(mlx->params));
	mlx->ptr = mlx_init();
	if (!(mlx->win = ft_open_window(mlx)))
		ft_error(NULL);
	if (!(mlx->img = ft_new_image(mlx, mlx->params->win_size.x, mlx->params->win_size.y)))
		ft_error(NULL);
    mlx->addrs = ft_image_addrs(mlx, mlx->img);
	ft_draw(mlx);
	mlx_hook(mlx->win, KEY_RELEASE_EVENT, KEY_RELEASE_MASK, key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
