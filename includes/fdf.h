/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:29 by yregragu          #+#    #+#             */
/*   Updated: 2024/08/04 20:34:58 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/libft.h"
# include "../includes/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

# define HEIGHT 1080
# define WIDTH 1440
# define PI 3.14159265358979323846

typedef struct s_2dcoord
{
	int			x1;
	int			y1;
}				t_2dcoord;

typedef struct s_map_coord
{
	int			abscissa;
	int			ordinate;
	int			altitude_min;
	int			altitude_max;
	int			***matrix;
}				t_map_coord;

typedef struct s_draw
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_draw;

typedef struct s_data
{
	void		*win;
	void		*mlx;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			cnstx;
	int			cnsty;
	int			flag;
	float		space;
	t_map_coord	*map;
	t_2dcoord	*dim;
	t_draw		*bres;
}				t_data;

typedef struct s_img
{
	void		*img;
	int			height;
	int			width;
}				t_img;

void			ft_initialize(t_data *fdf1);
void			check_map(int fd, t_data *fdf);
int				error_map_name(char *str);
void			ft_error(char *message);
int				get_height(char *filename);
int				get_width(char *filename);
void			ft_get_altitude_min_max(t_map_coord *map);
void			ft_get_map(char *str, t_data *fdf);
char			*get_next_line(int fd);
void			ft_fill_matrix(t_map_coord *map, int x, char *line);
void			draw_map(t_data *fdf);
void			isometric(t_data *fdf, int x, int y, int z);
void			iso_center(t_data *fdf, int x, int y, int z);
void			bresenham(int x0, int y0, t_data *data, int color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			rotate_z(t_2dcoord *dim, float x, float y, int angle);
void			rotate_x(t_2dcoord *dim, float y, float z, int angle);
void			rotate_y(t_2dcoord *dim, int x, int z, int angle);
#endif
