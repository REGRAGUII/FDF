/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:29 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/28 00:31:18 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../Libft/libft.h"
#include "../includes/get_next_line.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>

#define HEIGHT 800
#define	WIDTH 800

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

t_data	*ft_initialize(void);
int		error_map_name(char *str);
void	ft_error(char *message);
int		get_height(char *filename);
int		get_width(char *filename);
void	ft_get_altitude_min_max(t_map_coord *map);
void	ft_get_map(char *str, t_map_coord *map);
char	*get_next_line(int fd);
void	ft_fill_matrix(t_map_coord *map, char *line);
void	draw_map(t_data *fdf, t_map_coord map);
#endif