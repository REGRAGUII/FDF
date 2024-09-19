/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:19 by yregragu          #+#    #+#             */
/*   Updated: 2024/08/03 19:47:54 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *filename)
{
	char	*line;
	int		height;
	int		fd;

	height = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		width;
	char	*line;
	int		i;
	int		fd;

	i = 0;
	width = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line[i] && line[i] != '\n')
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
	close(fd);
	return (width);
}

void	ft_fill_matrix(t_map_coord *map, int x, char *line)
{
	char	**num;
	int		i;
	int		j;
	char	*tmp;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i] && i < map->abscissa)
	{
		map->matrix[x][i] = malloc(sizeof(int) * 2);
		j = 0;
		map->matrix[x][i][0] = ft_atoi(num[i]);
		while (num[i][j] && num[i][j] != ',')
			j++;
		tmp = num[i];
		if (num[i][j] == ',')
			map->matrix[x][i][1] = ft_atoi_base((tmp + j + 1),
					"0123456789ABCDEF");
		else
			map->matrix[x][i][1] = 0xFFFFFF;
		free(num[i]);
		i++;
	}
	free(num);
}

void	ft_get_altitude_min_max(t_map_coord *map)
{
	int	i;
	int	j;

	i = 0;
	map->altitude_min = 0;
	map->altitude_max = 0;
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

void	ft_get_map(char *filename, t_data *fdf)
{
	char	*line;
	int		i;
	int		fd;
	int		y;

	y = 0;
	fdf->map->abscissa = get_width(filename);
	fdf->map->ordinate = get_height(filename);
	fd = open(filename, O_RDONLY);
	i = 0;
	fdf->map->matrix = malloc(sizeof(int **) * fdf->map->ordinate);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fdf->map->matrix[i] = malloc(sizeof(int *) * fdf->map->abscissa);
		ft_fill_matrix(fdf->map, y, line);
		free(line);
		line = get_next_line(fd);
		i++;
		y++;
	}
	free(line);
	ft_get_altitude_min_max(fdf->map);
	close(fd);
}
