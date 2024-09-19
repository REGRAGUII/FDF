/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:43:51 by yregragu          #+#    #+#             */
/*   Updated: 2024/08/06 20:09:26 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error_map_name(char *str)
{
	int	n;
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	n = ft_strlen(str);
	if (n <= 4)
		return (1);
	if (!ft_strncmp(&str[n - 4], ".fdf", 4) && str[n - 5] != '/')
		return (0);
	return (1);
}

void	ft_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit(1);
}

void	free_split_line(char **split, char *line)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	free(line);
}

void	check_map(int fd, t_data *fdf)
{
	int		temp;
	int		i;
	char	*line;
	char	**num;

	temp = 0;
	line = get_next_line(fd);
	num = ft_split(line, ' ');
	while (num[temp])
		temp++;
	free_split_line(num, line);
	line = get_next_line(fd);
	while (line)
	{
		num = ft_split(line, ' ');
		i = 0;
		while (num[i])
			i++;
		free_split_line(num, line);
		if (i != temp)
			fdf->flag = 1;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}
