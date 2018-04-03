#include "fdf.h"

int		main(void)
{
	t_mlx	*mlx;
	t_point p1;
	t_point p2;
	t_point tmp;

	p1 = ft_newpoint(500, -500);
//	p1 = ft_newpoint(200, -200);
	p2 = ft_newpoint (200, -200);
//	p2 = ft_newpoint (500, -500);
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));

	mlx->ptr = mlx_init();
	mlx->win = ft_open_window(mlx);
	tmp.x = p1.x;
	while (tmp.x > p2.x)
	{
		tmp.y = ft_equline(p1, ft_pendant(p1, p2), tmp.x);
		ft_point(ft_newpoint(tmp.x, -tmp.y), mlx, 0x00FF00);
		tmp.x--;
	}
/*	while(tmp.x < p2.x)
	{
		tmp.y = ft_equline(p1, ft_pendant(p1, p2), tmp.x);
		ft_point(ft_newpoint(tmp.x, -tmp.y), mlx, 0x00FF00);
		tmp.x++;
	}*/

	mlx_loop(mlx->ptr);




	0x0000FF - 0x00FFFF - 0x00FF00 - 0xFFFF00 - 0xFF0000
}
