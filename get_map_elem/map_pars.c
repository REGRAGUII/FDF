/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:19 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/23 20:45:34 by yregragu         ###   ########.fr       */
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

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map->abscissa = get_width(&str);
	map->ordinate = get_height(&str);
	
 }