/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 02:13:09 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/26 01:23:17 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		length_pixel(int *pixel)
{
	int length;

	length = 1;
	while (*pixel != -1)
	{
		length++;
		pixel++;
	}
	return (length);
}

void	reallocpixels(int num, int **pixel)
{
	int		*new_pixel;
	int		length;
	void	*trash;

	length = length_pixel(*pixel);
	if (!(new_pixel = (int *)ft_memalloc(sizeof(int) * (length + 1))))
		ft_error(NULL);
	ft_memcpy(new_pixel, *pixel, length * sizeof(int));
	new_pixel[length - 1] = num;
	new_pixel[length] = -1;
	ft_memdel((void **)pixel);
	*pixel = new_pixel;
}

void	build_pixels(char *line, int **pixel)
{
	char *tmp;

	tmp = line;
	reallocpixels(ft_atoi(tmp), pixel);
	while ((tmp = ft_strchr(tmp, ' ')))
	{
		while (*tmp == ' ')
			tmp++;
		reallocpixels(ft_atoi(tmp), pixel);
		
	}
	reallocpixels(-2, pixel);
}

int *ft_lector(char *filename)
{
	int		fd;
	char	**line;
	int		*pixel;
	int		flag;

	if (!(pixel = (int *)ft_memalloc(sizeof(int))))
		ft_error(NULL);
	pixel[0] = -1;
	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_error(NULL);
	if (!(line = (char **)ft_strnew(sizeof(char *))))
		ft_error(NULL);
	while (1)
	{
		if ((flag = get_next_line(fd, line)) < 0)
			ft_error(NULL);
		else if (!flag)
			break ;
		build_pixels(*line, &pixel);
 		ft_strdel(line);
	}
	free(line);
//	if (!check_file(pixel))
//		ft_error("Wrong format file input");
	return (pixel);
}
