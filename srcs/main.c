/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 05:17:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 21:46:41 by jagarcia         ###   ########.fr       */
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
	void	*ptr_mlx;
	void	*win_mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	mlx->win = ft_open_window(mlx->ptr, 1000, 1000, "POLLA");
	mlx_key_hook(mlx->win, key_event, (void*)mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
