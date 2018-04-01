/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:13:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/01 20:49:48 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	wich_color(int move, int color)
{
	int	i;

	i = 0;
	while (i++ < move)
	{
		if ((color & 0x0000FF) == 0x0000FF && (color & 0x00FF00) != 0x00FF00
				&& (color & 0xFF0000) != 0xFF0000)
			color += 0x000100;
		else if (((color & 0x00FFFF) == 0x00FFFF) || ((color & 0x00FF00) ==
					0x00FF00 && (color | 0xFFFF00) != 0xFFFF00))
			color -= 0x000001;
		else if ((color & 0x00FF00) == 0x00FF00 && (color & 0x0000FF) !=
				0x0000FF && (color & 0xFF0000) != 0xFF0000)
			color += 0x010000;
		else if (((color & 0xFFFF00) == 0xFFFF00) || ((color & 0xFF0000) ==
					0xFF0000 && (color | 0xFF00FF) != 0xFF00FF))
			color -= 0x000100;
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

	if (pos == 1)
	{
		color1 = wich_color(set_pos(fmin(height, height2)), COLOR_DEEP);
		color2 = wich_color(set_pos(fmax(height, height2)), COLOR_DEEP);
		ini = color1;
	}
	if (height == height2)
		return (ini);
	color_scale = set_scale(height, height2, cuant);
	if ((color_scale * pos + set_pos(fmin(height, height2))) >=
			set_pos(fmax(height, height2)))
		return (ini);
	else
		return (ini = wich_color(color_scale, ini));
	return (ini);
}
