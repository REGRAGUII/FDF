/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:25 by yregragu          #+#    #+#             */
/*   Updated: 2024/08/06 18:15:19 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_initialize(t_data *fdf1)
{
	if (fdf1->flag)
	{
		free(fdf1);
		ft_putendl_fd("error: fdf file has irregular width", STDERR_FILENO);
		exit(1);
	}
	if (!fdf1)
		ft_error("allocation problem");
	fdf1->mlx = mlx_init();
	if (!fdf1->mlx)
		ft_error("fail in connection to graphic server");
	fdf1->win = mlx_new_window(fdf1->mlx, WIDTH, HEIGHT, "fil de fer <<FDF>>");
	if (!fdf1->win)
		ft_error("fail in initializing window");
	fdf1->img = mlx_new_image(fdf1->mlx, WIDTH, HEIGHT);
	if (!fdf1->img)
		ft_error("fail in initializing image");
	fdf1->addr = mlx_get_data_addr(fdf1->img, &fdf1->bpp, &fdf1->size_line,
			&fdf1->endian);
}

void	ft_initmap(t_data *fdf)
{
	fdf->dim = (t_2dcoord *)malloc(sizeof(t_2dcoord));
	fdf->map = (t_map_coord *)malloc(sizeof(t_map_coord));
	fdf->bres = (t_draw *)malloc(sizeof(t_draw));
	fdf->map->abscissa = 0;
	fdf->map->ordinate = 0;
	fdf->map->altitude_min = 0;
	fdf->map->altitude_max = 0;
	fdf->dim->x1 = 0;
	fdf->dim->y1 = 0;
	fdf->cnstx = 0;
	fdf->cnsty = 0;
	fdf->flag = 0;
	fdf->space = 0;
	fdf->map->matrix = NULL;
	fdf->bres->dx = 0;
	fdf->bres->dy = 0;
	fdf->bres->e2 = 0;
	fdf->bres->err = 0;
	fdf->bres->sx = 0;
	fdf->bres->sy = 0;
}

int	end(t_data *fdf)
{
	int	i;
	int	j;

	j = -1;
	while (++j < fdf->map->ordinate)
	{
		i = -1;
		while (++i < fdf->map->abscissa)
			free(fdf->map->matrix[j][i]);
		free(fdf->map->matrix[j]);
	}
	free(fdf->map->matrix);
	free(fdf->map);
	free(fdf->dim);
	free(fdf->bres);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	exit(0);
	return (0);
}

int	esc(int keycode, t_data *fdf)
{
	int	i;
	int	j;

	j = -1;
	if (keycode == 65307)
	{
		while (++j < fdf->map->ordinate)
		{
			i = -1;
			while (++i < fdf->map->abscissa)
				free(fdf->map->matrix[j][i]);
			free(fdf->map->matrix[j]);
		}
		free(fdf->map->matrix);
		free(fdf->map);
		free(fdf->dim);
		free(fdf->bres);
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
		free(fdf);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*fdf;
	int		fd;

	fdf = NULL;
	if (ac == 2)
	{
		if (error_map_name(av[1]))
			ft_error("Use two valid arguments|| example: ./fdf <testmap.fdf>");
		fd = open(av[1], O_RDONLY);
		fdf = malloc(sizeof(t_data));
		check_map(fd, fdf);
		ft_initialize(fdf);
		ft_initmap(fdf);
		ft_get_map(av[1], fdf);
		draw_map(fdf);
		mlx_hook(fdf->win, 17, 0, end, fdf);
		mlx_hook(fdf->win, 2, 1, esc, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_error("Use two valid arguments|| example: ./fdf <testmap.fdf>");
}
