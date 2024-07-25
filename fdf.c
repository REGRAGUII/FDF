/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:25 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/25 18:46:08 by youssef          ###   ########.fr       */
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
	// fdf1->cnstx = (fdf1->map->abscissa * 16 - (fdf1->map->abscissa - 1) * 16) / 2;
	// fdf1->cnsty = (fdf1->map->ordinate * 16 - (fdf1->map->ordinate - 1) * 16) / 2;

}
 
 static t_map_coord *ft_initmap(void)
 {
	t_map_coord	*map;
	
	map = (t_map_coord *)malloc(sizeof(t_map_coord));
	if(!map)
		ft_error("malloc error for map struct");
	map->abscissa = 0;
	map->ordinate = 0;
	map->altitude_min = 0;
	map->altitude_max = 0;
	map->matrix = NULL;
	return(map);
 }
 
int main(int ac, char **av)
{
	t_data	*fdf;
	
	
	if(ac == 2)
	{
		fdf = malloc(sizeof(t_data));
		fdf->map = ft_initmap();
		ft_get_map(av[1], fdf->map);
		ft_initialize(fdf);
		draw_map(fdf);
		mlx_loop(fdf->mlx);
	} 
	else
		ft_error("please use less argument example: ./fdf <testmap.fdf>");
}