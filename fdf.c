/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:25 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/23 12:36:31 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


 
int init_map(char *str, t_data *fdf)
{
	fdf->map = ft_get_map(&str); 
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "<<FDF>>");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_loop(fdf->mlx);
	
	
	
	return(0); 
}

int main(int ac, char **av) 
{
	t_data	fdf;

	if (ac == 2)
	{
		if (error_map_name(av[1]))
			ft_putstr_fd("invalid filename.", 2);
		if(init_map(av[1], &fdf))
			return (1);
	
	}
	else
		ft_putstr_fd("pleas use a test map", 2);
	
	
	return(0);
}