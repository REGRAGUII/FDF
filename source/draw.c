/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:17:26 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/27 23:38:11 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void draw_map(t_data *fdf)
{
	int	i;
	int	j;

	i = 0;
	while(i >= 0 && i <= fdf->map->ordinate)
	{
		j = 0;
		while(j >= 0 && j <= fdf->map->abscissa)
		{
			mlx_pixel_put(fdf->mlx, fdf->win, fdf->map)
		}
	}	
}