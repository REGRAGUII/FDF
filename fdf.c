/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:25 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/30 14:05:21 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_initialize(t_data *fdf1)
{
	
	if(!fdf1)
		ft_error("allocation problem");
	fdf1->mlx = mlx_init();
	if(!fdf1->mlx)
		ft_error("fail in connection to graphic server");
	fdf1->win = mlx_new_window(fdf1->mlx, WIDTH, HEIGHT, "fil de fer <<FDF>>");
	if(!fdf1->win)
		ft_error("fail in initializing window");
	fdf1->img = mlx_new_image(fdf1->mlx, WIDTH, HEIGHT);
	if(!fdf1->img)
		ft_error("fail in initializing image");
	fdf1->addr = mlx_get_data_addr(fdf1->img, &fdf1->bpp, &fdf1->size_line, &fdf1->endian);
}
 
 void	ft_initmap(t_data *fdf)
 {
	fdf->dim = (t_2dcoord *)malloc(sizeof(t_2dcoord));
	fdf->map = (t_map_coord *)malloc(sizeof(t_map_coord));
	if(!fdf->map)
		ft_error("malloc error for map struct");
	fdf->map->abscissa = 0;
	fdf->map->ordinate = 0;
	fdf->map->altitude_min = 0;
	fdf->map->altitude_max = 0;
	fdf->dim->x1 = 0;
	fdf->dim->y1 = 0;
	fdf->cnstx = 0;
	fdf->cnsty = 0;
	fdf->map->matrix = NULL;
 }
 

 int end(t_data *fdf)
 {
	int i;
	int j;

	j = 0;
	while (j < fdf->map->ordinate)
	{
		i = 0;
		while (i < fdf->map->abscissa)
		{
			free(fdf->map->matrix[j][i]);
			i++;
		}
		free(fdf->map->matrix[j]);
		j++;
	}
	free(fdf->map->matrix);
	free(fdf->map);
	free(fdf->dim);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit (1);
	return 0;
 }


 int esc(int keycode, t_data *fdf)
 {
	int i = 0;
	int j = 0;
	if (keycode == 65307)
	{
		while (j < fdf->map->ordinate)
		{
			i = 0;
			while (i < fdf->map->abscissa)
			{
				free(fdf->map->matrix[j][i]);
				i++;
			}
			free(fdf->map->matrix[j]);
			j++;
		}
		free(fdf->map->matrix);
		free(fdf->map);
		free(fdf->dim);
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
		exit(1);
	}
	return (0);
 }
 
 
 
int main(int ac, char **av)
{
	t_data	*fdf;
	
	
	if(ac == 2)
	{
		fdf = malloc(sizeof(t_data));
		ft_initmap(fdf);
		ft_get_map(av[1], fdf->map);
		ft_initialize(fdf);
		draw_map(fdf);
		mlx_hook(fdf->win, 17, 0, end, fdf);
		mlx_hook(fdf->win, 2, 1, esc, fdf);
		mlx_loop(fdf->mlx);
	} 
	else
		ft_error("please use two valid arguments || example: ./fdf <testmap.fdf>");
}

