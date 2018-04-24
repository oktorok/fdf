/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 05:17:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/24 07:02:41 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_event(int code, void *mlx)
{
//	ft_putnbr(code);
	if (code == ESCAPE)
	{
		mlx_destroy_window(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win);
		free(((t_mlx *)mlx)->params);
		free(((t_mlx *)mlx)->pixel);
		free(((t_mlx *)mlx));
		exit(1);
	}
	ft_coder(mlx, code);
	if (!(((t_mlx *)mlx)->img = ft_new_image(mlx)))
		ft_error(NULL);
	((t_mlx *)mlx)->addrs = ft_image_addrs(mlx);
	ft_draw(mlx);
	ft_print_image(mlx);
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
	if (!(((t_mlx *)mlx)->img = ft_new_image(mlx)))
		ft_error(NULL);
	((t_mlx *)mlx)->addrs = ft_image_addrs(mlx);
	ft_draw(mlx);
	mlx_hook(mlx->win, KEY_RELEASE_EVENT, KEY_RELEASE_MASK, key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
