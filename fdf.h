/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:29 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/23 12:35:30 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "Libft/libft.h"
#include <mlx.h>
#define HEIGHT 800
#define	WIDTH 800
#include <fcntl.h>

typedef struct s_map_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_map_coord;

typedef struct s_data
{
	void	*win;
	void	*mlx;
	void	*img;
	t_map_coord	*map;

} t_data;

typedef struct s_img
{
	void *img;
	int	height;
	int	width;
}	t_img;

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
}	t_coordinate;

int	error_map_name(char *str);


#endif