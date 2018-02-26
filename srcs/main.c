/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 05:17:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/26 20:24:58 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_event(int code, void *param)
{
//	ft_putnbr(code);
	if (code == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->ptr, ((t_mlx *)param)->win);
		exit(1);
	}
	if (code == 2)
	{
		ft_draw(param,code);
	}

	return (0);
}

int	main(void)
{
	t_mlx	*mlx;
	int		i;

	i = 0;
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->pixel = ft_lector("test");
	//////////////////////////////////
	while (mlx->pixel[i] != -1)
	{
		if (mlx->pixel[i] == -2)
			ft_putchar('\n');
		else
			ft_printf("<%i>",mlx->pixel[i]);
		i++;
	}
	//////////////////////////////////
	mlx->ptr = mlx_init();
	mlx->win = ft_open_window(mlx);
	mlx_key_hook(mlx->win, key_event, (void*)mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
