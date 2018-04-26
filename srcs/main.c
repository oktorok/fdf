/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 05:17:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/26 08:15:40 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_command(int argn, char **argv, int comm[2])
{
	int i;

	comm[0] = 0;
	comm[1] = 0;
	if (argn == 1 || argn > 7)
		ft_error(USAGE);
	i = 2;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'i' && argv[i + 1])
				comm[0] = i + 1;
			else if (argv[i][1] == 'd' && argv[i + 1] && argv[i + 2] &&
					ft_isdigit(argv[i + 1][0]) && ft_isdigit(argv[i + 2][0]))
				comm[1] = i++ + 1;
			else
				ft_error(USAGE);
			i += 2;
		}
		else
			ft_error(USAGE);
	}
}

static int		key_event(int code, void *mlx)
{
	t_mlx *mymlx;

	mymlx = (t_mlx *)mlx;
	if (code == ESCAPE)
	{
		ft_destroy_image(mymlx, mymlx->img);
		mlx_destroy_window(mymlx->ptr, mymlx->win);
		free(mymlx->params);
		free(mymlx->pixel);
		free(mymlx);
		exit(1);
	}
	ft_coder(mymlx, code);
	if (!(mymlx->img = ft_new_image(mymlx, mymlx->params->win_size.x,
					mymlx->params->win_size.y)))
		ft_error(NULL);
	mymlx->addrs = ft_image_addrs(mymlx->img, mymlx->params->win_size.x);
	ft_draw(mymlx);
	ft_print_image(mymlx, mymlx->img);
	ft_legend(mymlx);
	return (0);
}

int				main(int argn, char **argv)
{
	t_mlx		*mlx;
	int			comm[2];

	check_command(argn, argv, comm);
	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_error(NULL);
	mlx->pixel = ft_lector(argv[1]);
	ft_initialize(mlx->vector, &(mlx->params), argv, comm[1]);
	mlx->params->filename = argv[1];
	mlx->params->image_name = NULL;
	if (comm[0])
		mlx->params->image_name = argv[comm[0]];
	mlx->ptr = mlx_init();
	if (!(mlx->win = ft_open_window(mlx)))
		ft_error(NULL);
	mlx_hook(mlx->win, KEY_RELEASE_EVENT, KEY_RELEASE_MASK, key_event, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
