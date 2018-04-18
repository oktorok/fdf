/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 05:17:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/18 03:18:09 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_event(int code, void *mlx)
{
	ft_putnbr(code);
	if (code == ESCAPE)
	{
		mlx_destroy_window(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win);
		exit(1);
	}
	ft_coder(mlx, code);
	((t_mlx *)mlx)->img = ft_new_image(mlx);
	((t_mlx *)mlx)->addrs = ft_image_addrs(mlx);
	ft_draw(mlx);
	ft_print_image(mlx);
	return (0);
}

int	main(int argn, char **argv)
{
	t_mlx		*mlx;
	int			i;

	if (argn != 2)
	{
		ft_printf("Usage: fdf file_path\n");
		return (-1);
	}
	i = 2;
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->pixel = ft_lector(argv[1]);
	ft_printf("(%f, %f, %f)\n", mlx->vector[0].x, mlx->vector[0].y, mlx->vector[0].z);
	mlx->params = ft_initialize(mlx->pixel, mlx->vector);
	ft_printf("(%f, %f, %f)\n", mlx->vector[0].x, mlx->vector[0].y, mlx->vector[0].z);
	mlx->ptr = mlx_init();
	mlx->win = ft_open_window(mlx);
	mlx_hook(mlx->win, KEY_RELEASE_EVENT, KEY_RELEASE_MASK, key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
