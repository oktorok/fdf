/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:13:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/28 13:19:36 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	wich_color(int position)
{
	int color;
	
	color = 0x0000FF;
	while (position)
	{
		if ((color & 0x0000FF) == 0x0000FF && (color & 0x00FF00) != 0x00FF00 && (color & 0xFF0000) != 0xFF0000)
			color += 0x000100;
		else if (((color & 0x00FFFF) == 0x00FFFF) || ((color & 0x00FF00) == 0x00FF00 && (color | 0xFFFF00) != 0xFFFF00))
			color -= 0x000001;
		else if ((color & 0x00FF00) == 0x00FF00 && (color & 0x0000FF) != 0x0000FF && (color & 0xFF0000) != 0xFF0000)
			color += 0x010000;
		else if (((color & 0xFFFF00) == 0xFFFF00) || ((color & 0xFF0000) == 0xFF0000 && (color | 0xFF00FF) != 0xFF00FF))
			color -= 0x000100;
		position--;
	}
	return (color);
}

int	ft_get_color(int height, int height2, int cuant, int pos)
{
	int color1;
	int color2;
	int color;

	color1 = (height - DEEP_VALUE) * COLOR_SCALE;
	color2 = (height2 - DEEP_VALUE) * COLOR_SCALE;
	if (color1 == color2)
		color = wich_color(color1);
	else if (color1 < color2)
		color = wich_color(((color2 - color1) / cuant * pos) + color1);
	else if (color2 < color1)
	{
		color = wich_color((cuant / (color1 - color2) * pos) + color2);
	ft_printf("De %i a %i, son %i pixeles y es el pixel %i, obtengo el color %x\n",height, height2, cuant, pos, color);
	ft_printf("Color1 es %i, Color2 es %i, la escala es %i\n", color1, color2, COLOR_SCALE);
	}
	return (color);
}
