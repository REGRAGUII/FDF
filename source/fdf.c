/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:25 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/27 23:41:26 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_data	*ft_initialize(void)
{
	t_data	*fdf1;
	
	fdf1 = malloc(sizeof(t_data));
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
	fdf1->addr = mlx_get_data_addr(fdf1->mlx, &fdf1->bpp, &fdf1->size_line, &fdf1->endian);
	return(fdf1); 	
}
 
 static t_map_coord *ft_initmap(void)
 {
	t_map_coord	*map;
	
	map = (t_map_coord *)malloc(sizeof(t_map_coord));
	if(!map)
		ft_error("malloc error for map struct");
	map->abscissa = 0;
	map->ordinate = 0;
	map->altitude_max = 0;
	map->altitude_max = 0;
	map->matrix = NULL;
	return(map);
 }
 
int main(int ac, char **av)
{
	t_data	*fdf;
	
	if(ac == 2)
	{
		fdf = ft_initialize();
		fdf->map = ft_initmap();
		ft_get_map(av[1], fdf->map);
		draw_map(fdf, fdf->map);
		mlx_loop(fdf->mlx);
	} 
	else
		ft_error("please use less argument example: ./fdf <testmap.fdf>");
}