/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:29 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/23 17:16:34 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "Libft/libft.h"
#include <mlx.h>
#define HEIGHT 800
#define	WIDTH 800
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_map_coord
{
	int	abscissa;
	int	ordinate;
	int altitude_min;
	int altitude_max;
	int	***ar;
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

int			error_map_name(char *str);
void		ft_error(char *message);
static int	get_height(char *file);
static int	get_width(char *file)


#endif