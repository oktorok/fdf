/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:13:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/24 03:29:16 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	color_move(int color, int i, int mask, int *move)
{
	int flag[2];

	flag[1] = 1;
	flag[0] = 1;
	if (color < 0)
		color *= (flag[0] = -1);
	if (mask < 0)
	{
		mask *= (flag[1] = -1);
		flag[0] *= -1;
	}
	if ((color * flag[1]) + (*move << (flag[0] > 0 ? i : (i - 8))) >
			mask * flag[1])
	{
		*move -= (labs(mask - color)) >> (flag[0] > 0 ? i : (i - 8));
		return (mask);
	}
	else
	{
		color += (*move << (flag[0] > 0 ? i : (i - 8))) * flag[1];
		*move = 0;
	}
	return (color);
}

static int	wich_color(int move, int color, int flag, int color2)
{
	int	i;
	int mask_a;
	int mask_tmp;
	int mask_b;

	mask_a = flag > 0 ? COLOR_DEEP : COLOR_HIGH;
	mask_b = flag > 0 ? (COLOR_DEEP | (COLOR_DEEP << 8)) :
		(COLOR_HIGH | (COLOR_HIGH >> 8));
	i = flag > 0 ? 8 : 16;
	while (move)
	{
		if ((color & mask_a) == mask_a && (color & mask_b) != mask_b)
			color = color_move(flag > 0 ? color : -color, i, mask_b, &move);
		mask_tmp = flag > 0 ? mask_a << 8 : mask_a >> 8;
		if ((color & mask_tmp) == mask_tmp && ((color & mask_a) != 0))
			color = color_move(flag > 0 ? color : -color, i, -mask_tmp, &move);
		mask_b = flag > 0 ? mask_b << 8 : mask_b >> 8;
		mask_a = flag > 0 ? mask_a << 8 : mask_a >> 8;
		if ((i != 8 && flag < 0) || (i != 16 && flag > 0))
			i = flag > 0 ? i + 8 : i - 8;
		if (color == color2)
			return (color2);
	}
	return (color);
}

static int	set_pos(int height)
{
	int color_pos;

	color_pos = (height - DEEP_VALUE) * COLOR_SCALE;
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
		return (1);
}

int			ft_get_color(int height, int height2, int cuant, int pos)
{
	static int	color1;
	static int	color2;
	int			color_scale;
	static int	ini = 0;

	if (pos == 1)
	{
		color1 = wich_color(set_pos(height), COLOR_DEEP, 1, COLOR_HIGH);
		color2 = wich_color(set_pos(height2), COLOR_DEEP, 1, COLOR_HIGH);
		ini = color1;
	}
	if (ini == color2)
		return (color2);
	color_scale = set_scale(height, height2, cuant);
	return (ini = wich_color(color_scale, ini, height < height2 ? 1 : -1,
				color2));
}
