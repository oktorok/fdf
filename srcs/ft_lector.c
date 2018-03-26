/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 02:13:09 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/26 01:46:00 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reallocpixels(int num, int **pixel, int nums)
{
	int		*new_pixel;
	void	*trash;
	int		length;

	length = (*pixel)[0] * (*pixel)[1] + 3 + nums;
	if (!(new_pixel = (int *)ft_memalloc(sizeof(int) * length)))
		ft_error(NULL);
	ft_memcpy(new_pixel, *pixel, (length - 1) * sizeof(int));
	new_pixel[length - 1] = num;
	ft_memdel((void **)pixel);
	*pixel = new_pixel;
}

void		build_pixels(char *line, int **pixel)
{
	int		i;
	int		nums;
	static int cuant = 0;

	i = 0;
	nums = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i])
		{
			if (ft_atoi(line + i) == 0)
			{
				cuant++;
				if (cuant == 15)
					ft_putstr(line);
			}
			reallocpixels(ft_atoi(line + i), pixel, nums);
			nums++;
		}
		while (line[i] != ' ' && line[i])
			i++;
	}
	(*pixel)[0]++;
	if (nums != (*pixel)[1])
		ft_error("Wrong format file input");
	ft_printf("hay %i zeros\n", cuant);
}

static int	first_step(int fd, char **line, int **pixel)
{
	int flag;
	int	i;

	i = 0;
	(*pixel)[0] = 0;
	(*pixel)[1] = 0;
	if ((flag = get_next_line(fd, line)) < 0)
		ft_error(NULL);
	while ((*line)[i])
	{
		while ((*line)[i] == ' ')
			i++;
		if ((*line)[i])
			(*pixel)[1]++;
		while ((*line)[i] != ' ' && (*line)[i])
			i++;
	}
	return (flag);
}

int			*ft_lector(char *filename)
{
	int		fd;
	char	**line;
	int		*pixel;
	int		flag;

	if (!(pixel = (int *)ft_memalloc(sizeof(int) * 2)))
		ft_error(NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_error(NULL);
	if (!(line = (char **)ft_memalloc(sizeof(char *))))
		ft_error(NULL);
	flag = first_step(fd, line, &pixel);
	while (flag)
	{
		build_pixels(*line, &pixel);
		ft_strdel(line);
		if ((flag = get_next_line(fd, line)) < 0)
			ft_error(NULL);
	}
	free(line);
	return (pixel);
}
