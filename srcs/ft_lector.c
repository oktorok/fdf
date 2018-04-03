/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 02:13:09 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/02 21:12:03 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reallocpixels(int **pixel, int reall_cuan, int act_row, int final)
{
	int	*new_pixel;
	int	comple_rows;

	comple_rows = (*pixel)[0] * (*pixel)[1];
	if (!final)
	{
		new_pixel = (int *)ft_memalloc(sizeof(int) *
				(BUFFER_INT * reall_cuan + 2));
		ft_memcpy(new_pixel, *pixel, sizeof(int) * (comple_rows + act_row + 2));
		ft_memdel((void **)pixel);
		*pixel = new_pixel;
	}
	else
	{
		new_pixel = (int *)ft_memalloc(sizeof(int) * (comple_rows + 2));
		ft_memcpy(new_pixel, *pixel, (sizeof(int) * (comple_rows + 2)));
		ft_memdel((void **)pixel);
		*pixel = new_pixel;
	}
}

void		build_pixels(char *line, int **pixel)
{
	int			i;
	char		**nums;
	int			row_len;
	static int	reall_flag = 1;

	i = 0;
	row_len = 0;
	nums = ft_strsplit(line, ' ');
	if (!((*pixel)[1]))
		while (nums[i++])
			(*pixel)[1]++;
	i = (*pixel)[1] * (*pixel)[0] + 2;
	while (*nums)
	{
		if ((*pixel)[0] * (*pixel)[1] + ++row_len > BUFFER_INT * reall_flag)
			reallocpixels(pixel, ++reall_flag, row_len, 0);
		(*pixel)[i++] = ft_atoi(*nums++);
	}
	(*pixel)[0]++;
	if (row_len != (*pixel)[1])
		ft_error("Wrong format file input");
}

int			*ft_lector(char *filename)
{
	int		fd;
	char	**line;
	int		*pixel;
	int		flag;

	if (!(pixel = (int *)ft_memalloc(sizeof(int) * (BUFFER_INT + 2))))
		ft_error(NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_error(NULL);
	if (!(line = (char **)ft_memalloc(sizeof(char *))))
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
	reallocpixels(&pixel, 0, 0, 1);
	free(line);
	return (pixel);
}
