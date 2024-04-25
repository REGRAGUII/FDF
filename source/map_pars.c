/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:19 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/25 23:07:11 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	get_height(char *file, int fd)
{
	char *line;
	int height;

	height = 0;
	line = get_next_line(fd);
	if(!line)
		ft_error("reading line error");
	while(get_next_line(fd))
	{
		height++;
		free(line);
	}
	free(line);
	return(height);
}


static int	get_width(char *file, int fd)
{
	int		width;
	char	*line;
	int		i;

	i = 0;
	width = 0;
	line = get_next_line(fd);
	if (*line == '\0')
		ft_error("invalid map (empty)");
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			width++;
		i++;
	}
	free(line);
	return (width);	
}

static void	fill_table(int **matrix, char *line, int abscissa)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = -1;
	while (num[++i] && i < abscissa)
	{
		matrix[i] = malloc(sizeof(int) * 2);
		if (!matrix[i])
			ft_error("malloc error");
		matrix[i][0] = ft_atoi(num[i]);
		j = 0;
		while (num[i][j] && num[i][j] != ',')
			j++;
		if (num[i][j] == ',')
			matrix[i][1] = ft_atoi_base(&num[i][++j], "0123456789ABCDEF");
		else
			matrix[i][1] = -1;
		free(num[i]);
	}
	if (i != abscissa || num[i])
		ft_error("error: fdf file has irregular width");
	free(num);
}

static void	ft_get_altitude_min_max(t_map_coord *map)
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

void	ft_get_map(char *str, t_map_coord *map)
 {
	int	fd;
	int	i;
	char *line;

	line = NULL;	
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("open file fail");
	map->abscissa = get_width(str, fd);
	map->ordinate = get_height(str, fd);
	i = -1;
	map->matrix = malloc(sizeof(int **) * map->ordinate);
	if (!map->matrix)
		ft_error("malloc error");
	while (line == get_next_line(fd))
	{
		map->matrix[++i] = malloc(sizeof(int *) * map->abscissa);
		if (!map->matrix[i])
			ft_error("malloc error");
		fill_table(map->matrix[i], line, map->abscissa);
		free(line);
	}
	free(line);
	ft_get_altitude_min_max(map);
	if (close(fd) == -1)
		ft_error("close error");
 }
