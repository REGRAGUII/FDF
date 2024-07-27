/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:19 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/26 17:46:07 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	print_hex(int p)
{
	char *str;
	int i;

	str = "0123456789abcdef";
	if (p == 0)
		return (0);
	while (p)
	{
		i *= 16;
		i = str[p % 16];
		p /= 16;
	}
	return(i);
}

int	get_height(char *filename)
{
	char *line;
	int height;
	int fd;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	line = get_next_line(fd);
	if(!line)
		ft_error("reading line error");
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	if(close(fd) == -1)
		ft_error("close error <height>");
	return(height);
}

int	get_width(char *filename)
{
	int		width;
	char	*line;
	int		i;
	int 	fd;

	i = 0;
	width = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	line = get_next_line(fd);
	if (!line)
		ft_error("invalid map (empty)");
	while(line[i] && line[i] != '\n')
	{
		while (line[i] && line[i] != '\n' && line[i] == ' ')
			i++;
		if (line[i] && line[i] != '\n')
		{
			width++;
			while (line[i] && line[i] != '\n' && line[i] != ' ')
				i++;
		}
	}
	free(line);
	if(close(fd) == -1)
		ft_error("close error <width>");
	return (width);	
}



void	ft_fill_matrix(t_map_coord *map, char *line)
{
	char	**num;
	int		i;
	int		j;
	char	*tmp;
	static int x = 0;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i] && i < map->abscissa)
	{
		map->matrix[x][i] = malloc(sizeof(int) * 2);
		if (!map->matrix[x][i])
			ft_error("malloc error");
		j = 0;
		map->matrix[x][i][0] = ft_atoi(num[i]);
		while (num[i][j] && num[i][j] != ',')
			j++;
		tmp = num[i];
		if (num[i][j] == ',')
			map->matrix[x][i][1] = ft_atoi_base((tmp + j + 1), "0123456789ABCDEF");

		else
			map->matrix[x][i][1] = -1;
		free(num[i]);
		i++;
	}
	if (i != map->abscissa)
		ft_error("error: fdf file has irregular width");

	free(num);
	x++;
}

void	ft_get_altitude_min_max(t_map_coord *map)
{
	int	i;
	int	j;

	i = 0;
	map->altitude_min = map->matrix[0][0][0];
	map->altitude_max = map->matrix[0][0][0];
	while (i < map->ordinate)
	{
		j = 0;
		while (j < map->abscissa)
		{
			if (map->matrix[i][j][0] < map->altitude_min)
				map->altitude_min = map->matrix[i][j][0];
			if (map->matrix[i][j][0] > map->altitude_max)
				map->altitude_max = map->matrix[i][j][0];
			j++;
		}
		i++;
	}
}

void	ft_get_map(char *filename, t_map_coord *map)
{
	char	*line;
	int		i;
	int		fd;

	map->abscissa = get_width(filename);
	map->ordinate = get_height(filename);
	
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	i = 0;
	map->matrix = malloc(sizeof(int **) * map->ordinate);
	if (!map->matrix)
		ft_error("malloc error");
	while ((line = get_next_line(fd)) != NULL)
	{
		map->matrix[i] = malloc(sizeof(int *) * map->abscissa);
		if(!map->matrix[i])
			ft_error("malloc error");
		ft_fill_matrix(map, line);
		free(line);
		i++;
	}
	ft_get_altitude_min_max(map);
	if (close(fd) == -1)
		ft_error("file close error");
}
