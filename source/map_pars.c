/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:19 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/26 23:06:13 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char **free_mem(char **str)
{
	int	i;
	
	i = -1;
	if (str)
	{
		while (str[++i])
			free(str[i]);
		free(str);
	}
	return (NULL);
}


int	get_height(int fd)
{
	char *line;
	int height;

	height = 0;
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

int	get_width(int fd)
{
	int		width;
	char	*line;
	int		i;
	char	**str;

	i = 0;
	width = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error("invalid map (empty)");
	str = ft_split(line, ' ');
	while (str[i])
	{
		if(!ft_strchr(str[i], '\n'))
			width++;
		i++;
	}
	free(line);
	str = free_mem(str);
	if(close(fd) == -1)
		ft_error("close error <width>");
	return (width);	
}
void	print_table(int **matrix)
{
	int i =0;
	while (/* condition */)
	{
		/* code */
	}
	
}
void	fill_table(int **matrix, char *line, int abscissa)
{
	char	**num;
	int		i;
	int		j;

	num = ft_split(line, ' ');
	i = 0;
	while (num[i] && i < abscissa)
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
		i++;
	}
	if (i != abscissa || num[i])
		ft_error("error: fdf file has irregular width");
	free(num);
}

void	ft_get_altitude_min_max(t_map_coord *map)
{
	int	i;
	int	j;

	i = 0;
	map->altitude_min = 0;
	map->altitude_max = 0;
	while (i < map->ordinate)
	{
		j = 0;
		while (j < map->abscissa)
		{
			if (map->matrix[i][j] < map->altitude_min)
				map->altitude_min = map->matrix[i][j];
			if (map->matrix[i][j] > map->altitude_max)
				map->altitude_max = map->matrix[i][j];
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
	map->ordinate = get_height(fd);
	fd = open(str, O_RDONLY);
	printf("ordinat -> %d", map->ordinate);
	map->abscissa = get_width(fd);
	printf("abscissa -> %d", map->abscissa);
	i = -1;
	map->matrix = malloc(sizeof(int *) * map->ordinate);
	if (!map->matrix)
		ft_error("malloc error");
	line  = get_next_line(fd);
	while (line)
	{
		map->matrix[++i] = malloc(sizeof(int) * map->abscissa);
		if (!map->matrix[i])
			ft_error("malloc error");
		fill_table(map->matrix, line, map->abscissa);
		free(line);
	}
	free(line);
	ft_get_altitude_min_max(map);
	if (close(fd) == -1)
		ft_error("close error");
 }
