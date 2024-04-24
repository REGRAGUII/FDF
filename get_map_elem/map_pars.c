/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:19 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/24 14:29:11 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *file)
{
	char *line;
	int	fd;
	int height;

	height = 0;
	fd = open("file", O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	line = get_next_line(fd);
	if(!line)
		return(NULL);
	while(get_next_line(fd))
	{
		height++;
		free(line);
	}
	free(line);
	if(close(fd) == -1)
		ft_error("error");
	return(height);
}


static int	get_width(char *file)
{
 	int		fd;
	int		width;
	char	*line;
	int		i;

	i = 0;
	fd = open("file", O_RDONLY);
	if (fd == -1)
		ft_error("open error");
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
	while (get_next_line(fd))
		free(line);
	free(line);
	if (close(fd) == -1)
		ft_error("close error");
	return (width);	
}



void	ft_get_map(char *str, t_map_coord *map)
 {
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map->abscissa = get_width(&str);
	map->ordinate = get_height(&str);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("open error");
	i = -1;
	map->ar = malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_return_error("malloc error", 1);
	while (get_next_line(fd) >= 0 && *line != '\0')
	{
		map->ar[++i] = malloc(sizeof(int *) * map->abscissa);
		if (!map->ar[i])
			ft_return_error("malloc error", 1);
		fill_table(map->ar[i], line, map->abscissa);
		free(line);
	}
	free(line);
	ft_get_z_min_max(map);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
 }