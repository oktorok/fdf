/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 09:13:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/03 19:12:37 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*hextorgb(int color)
{
	char rgb[3];

	rgb[0] = color & 0xFF0000;
	rgb[1] = color & 0x00FF00;
	rgb[2] = color & 0x0000FF;
	return (rgb);
}

static int	wich_color(int move, int color, int flag)
{

	char	rgb[3];
	int		i;

	rgb = hextorgb(color);
	i = 2;
	while (rgb[i] != 0xFF)
		i--;

/*	int	i;
	int diff;
	int mask_a;
	int mask_b;
	int tmp;

	mask_a = flag > 0 ? 0x0000FF : 0xFF0000;
	mask_b = flag > 0 ? 0x00FFFF : 0xFFFF00;
	i = flag > 0 ? 8 : 16;
	diff = 1;
	ft_printf("[move = %i]\n",move);
	ft_printf("[flag = %i]\n",flag);
	ft_printf("[color = %#0.6x]\n", color);
	ft_putstr("EMPIEZO\n");
	while (move)
	{
		ft_printf("{amask = %#0.6x, bmask = %#0.6x}\n",mask_a, mask_b);
		if ((color & mask_a) == mask_a && (color & mask_b) != mask_b)
		{
			ft_printf("ACOLOR = %#0.6x\n",color);
			if (mask_b - ((move % 0xFF) << (i - 8) > mask_b))
			{
				if (flag > 0)
					color = mask_b - ((((mask_b >> (i - 8)) - move) % 0xFF) << (i - 8));
				else
					color = mask_b - ((((mask_b >> i) - move) % 0xFF) << i);
				//	color = mask_b - ((move % 0xFF) << i);
				if (move > (0xFF * 2))
					move = move - 0xFF;
				else
					break;
				ft_printf("Amove = %i\n", move);
			}
			else
			{
				if (flag > 0)
					color += move << i;
				else
					color += (move << (i - 8));
				break ;
			}
		}
		i = flag > 0 ? i + 8 : i - 8;
		if ((color & (mask_a << 8)) == (mask_a << 8) && (color & mask_a) != 0)
		{
			ft_printf("BCOLOR = %#0.6x\n",color);
			if (move >= 0xFF)
			{
				if (flag > 0)
					color = (mask_a << 8) + ((move % 0xFF) << i);
				else
					color = (mask_a << 8) + ((move % 0xFF) << (i - 8));
				if (move > (0xFF * 2))
					move = move - 0xFF;
				else
					break;
				ft_printf("Bmove = %i\n", move);
			}
			else
			{
				if (flag > 0)
					color -= move << (i - 16);
				else
					color -= move << (i + 8);
				break ;
			}
		}
		mask_a = flag > 0 ? mask_a << 8 : mask_a >> 8;
		mask_b = flag > 0 ? mask_b << 8 : mask_b >> 8;
		if ((mask_a == 0xFF0000 && flag > 0) || (mask_a == 0x0000FF && flag < 0))
		{
			color = mask_a;
			break ;
		}
//		if (flag > 0)
//			i += 8;
//		else
//			i -= 8;
	}
	ft_printf("FCOLOR = %#0.6x\n", color);
	ft_putstr("ACABO\n");
/*	while (diff)
	{
		ft_printf("{amask = %#0.6x, bmask = %#0.6x}\n",mask_a, mask_b);
		if ((color & mask_a) == mask_a && (color & mask_b) != mask_b)
		{
			ft_printf("ACOLOR = %#0.6x\n",color);
			if ((diff = (((mask_b - (color & mask_b)) >> i) - move)) < 0)
			{
				if (flag > 0 )
					color += ((diff + move) << i);
				else
					color += ((diff + move) << i);
				move = -diff;
				ft_printf("Amove = %i\n", move);
			}
			else
			{
				color += move << i;
				break ;
			}
		}
		if ((color & (mask_a << 8)) == (mask_a << 8) && (color & mask_a) != 0)
		{
			ft_printf("BCOLOR = %#0.6x\n",color);
			if ((diff = ((mask_a >> (i - 8)) - move)) < 0)
			{
				if (flag > 0)
					color -= ((diff + move) << (i - 8));
				else
					color -= ((diff + move) << (i - 8));
				move = -diff;
				ft_printf("Bmove = %i\n", move);
			}
			else
			{
				color -= move << (i - 8);
				break ;
			}
		}
		mask_a = flag > 0 ? mask_a << 8 : mask_a >> 8;
		mask_b = flag > 0 ? mask_b << 8 : mask_b >> 8;
		if ((mask_a == 0xFF0000 && flag > 0) || (mask_a == 0x0000FF && flag < 0))
		{
			color = mask_a;
			break ;
		}
		if (flag > 0)
			i += 8;
		else
			i -= 8;
	}*/

/*	while (i++ < move)
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
	}*/
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
