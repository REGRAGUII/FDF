/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:25 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/25 22:58:22 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_data	*ft_initialize(char *filename)
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
	fdf1->addr = mlx_get_data_addr(fdf1->mlx, &fdf1->bpp, fdf1->size_line, fdf1->endian); 
	
}
 
int main(int ac, char **av)
{
	t_data	*fdf;
	t_map_coord *map;
	
	fdf = ft_initialize(av[1]);
	ft_get_map(av[1], map);
	printf("%d, %d, %d, %d, %d", map->abscissa, map->ordinate, map->altitude_max, map->altitude_min);
	
}