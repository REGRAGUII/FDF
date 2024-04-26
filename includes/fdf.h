/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:29 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/26 22:55:00 by yregragu         ###   ########.fr       */
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
	int	**matrix;
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

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
}	t_coordinate;



char **free_mem(char **str);
t_data	*ft_initialize(void);
int			error_map_name(char *str);
void		ft_error(char *message);
int	get_height(int fd);
int	get_width(int fd);
void	ft_get_altitude_min_max(t_map_coord *map);
void	ft_get_map(char *str, t_map_coord *map);
void	fill_table(int **matrix, char *line, int abscissa);
char	*get_next_line(int fd);
#endif