/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:36:19 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/23 13:14:04 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
t_map_coord get_width(int fd)
{
	char *str;
	t_map_coord map;

	str = get_next_line(fd);
	if(!str)
		return(NULL);
	while(str)
	{
		map->x += 1;
		str++;
	}
	return(map);
}
t_map_coord	ft_get_map(char *str)
 {
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (NULL);
	get_height(&fd);
	get_width(&fd);	
 }