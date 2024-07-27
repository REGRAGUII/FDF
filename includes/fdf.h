/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:29 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/27 16:00:13 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../Libft/libft.h"
#include "../includes/get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 1800
#define	WIDTH 1800
#define PI 3.14159265358979323846

typedef struct s_map_coord
{
	int	abscissa;
	int	ordinate;
	int altitude_min;
	int altitude_max;
	int	***matrix;
}	t_map_coord;


typedef struct s_data
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;	
	int		cnstx;
	int		cnsty;
	t_map_coord	*map;

} t_data;

typedef struct s_img
{
	void *img;
	int	height;
	int	width;
}	t_img;

// typedef struct s_3dcoord
// {
// 	int	x;
// 	int	y;
// 	int	z;
// }	t_3dcoord;

// typedef struct s_2dcoord
// {
// 	int	x;
// 	int y;
// }	t_2dcoord;

void	ft_initialize(t_data *fdf1);
int		error_map_name(char *str);
void	ft_error(char *message);
int		get_height(char *filename);
int		get_width(char *filename);
void	ft_get_altitude_min_max(t_map_coord *map);
void	ft_get_map(char *str, t_map_coord *map);
char	*get_next_line(int fd);
void	ft_fill_matrix(t_map_coord *map, char *line);
void	draw_map(t_data *fdf);
#endif