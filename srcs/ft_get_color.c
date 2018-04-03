/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:13:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/04 01:36:24 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	wich_color(int move, int color, int flag)
{

	int	i;
	int mask_a;
	int mask_b;

	mask_a = flag > 0 ? 0x0000FF : 0xFF0000;
	mask_b = flag > 0 ? 0x00FFFF : 0xFFFF00;
	i = flag > 0 ? 8 : 16;
	while (move)
	{
		if (mask_a == 0)
			break ;
		if ((color & mask_a) == mask_a && (color & mask_b) != mask_b)
		{
			if (color + (move << (flag > 0 ? i : (i - 8))) > mask_b)
			{
				move -= (mask_b - color) >> (flag > 0 ? i : (i - 8));
				color = mask_b;
			}
			else
			{
				color += move << (flag > 0 ? i : (i - 8));
				break ;
			}
		}
		if ((color == 0xFF0000 && flag > 0) || (color == 0x0000FF && flag < 0))
			break ;

		if ((color & (flag > 0 ? mask_a << 8 : mask_a >> 8)) == (flag > 0 ? mask_a << 8 : mask_a >> 8) && ((color & mask_a) != 0))
		{
			if (color - (move << (flag > 0 ? (i - 8) : i)) < (flag > 0 ? mask_a << 8 : mask_a >> 8))
			{
				move -= (color - (flag > 0 ? mask_a << 8 : mask_a >> 8)) >> (flag > 0 ? (i - 8) : i);
				color = (flag > 0 ? mask_a << 8 : mask_a >> 8);
			}
			else
			{
				color -= move << (flag > 0 ? (i - 8) : i);
				break ;
			}
		}
		if (mask_a != 0x00FF00)
			mask_b = flag > 0 ? mask_b << 8 : mask_b >> 8;
		mask_a = flag > 0 ? mask_a << 8 : mask_a >> 8;
		if (i != 8 && flag < 0 || i != 16 && flag > 0)
			i = flag > 0 ? i + 8 : i - 8;
		if ((color == 0xFF0000 && flag > 0) || (color == 0x0000FF && flag < 0))
			break ;
	}
	return (color);
}

static int	set_pos(int height)
{
	int color_pos;

	color_pos = (height - DEEP_VALUE) * COLOR_SCALE;
	if (color_pos < 0)
		color_pos = 0;
	return (color_pos);
}

static int	set_scale(int height, int height2, int cuant)
{
	int start;
	int end;

	start = set_pos(height);
	end = set_pos(height2);
	if (cuant < labs(start - end))
		return (labs(start - end) / cuant);
	else
		return (cuant / labs(start - end));
}

int			ft_get_color(int height, int height2, int cuant, int pos)
{
	static int	color1;
	static int	color2;
	int			color_scale;
	static int	ini = 0;

//	ft_printf("pos 1 = %i, pos 2 = %i \n", set_pos(height), set_pos(height2));
//	if (height != height2)
//	color1 = wich_color(set_pos(height2), COLOR_DEEP, 1);
//	ft_printf("%#0.6x\n", color1);

//	return (0xFFFFFF);
	if (pos == 1)
	{
		color1 = wich_color(set_pos(height), COLOR_DEEP, 1);
		color2 = wich_color(set_pos(height2), COLOR_DEEP, 1);
		ini = color1;
//		if (height != height2)
//		ft_printf("H = %i, H2 = %i, min = %i, max = %i\n", height, height2, (int)fmin(height, height2), (int)fmax(height, height2));
	}
	if (height == height2)
		return (ini);
	color_scale = set_scale(height, height2, cuant);
	if ((color_scale * pos + set_pos(height)) >=
			set_pos(height2) && height < height2)
		return (ini);
	if (set_pos(height) - color_scale * pos <=
			set_pos(height2) && height > height2)
		return (ini);
	else
		return (ini = wich_color(color_scale, ini, height < height2 ? 1 : -1));
	return (0xFFFFFF);

}
