/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 05:17:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/18 02:02:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_event(int code, void *param)
{
	ft_putnbr(code);
	if (code == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->ptr, ((t_mlx *)param)->win);
		exit(1);
	}
	else
	{
		ft_draw(param,code);
	}

	return (0);
}

int	main(int argn, char **argv)
{
	t_mlx	*mlx;
	int		i;

	if (argn != 2)
	{
		ft_printf("Usage: fdf file_path\n");
		return (-1);
	}
	i = 2;
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->pixel = ft_lector(argv[1]);
	/////////////////////////////////
	while (i < mlx->pixel[1] * mlx->pixel[0] + 2)
	{
		if (!((i - 2) % (mlx->pixel[1])))
			ft_putchar('\n');
		ft_printf("<%i>",mlx->pixel[i]);
		i++;
	}
	/////////////////////////////////
	mlx->ptr = mlx_init();
	mlx->win = ft_open_window(mlx);
	mlx_key_hook(mlx->win, key_event, (void*)mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
