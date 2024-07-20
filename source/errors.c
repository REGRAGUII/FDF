/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:43:51 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/26 21:47:03 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	error_map_name(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n <= 4)
		return (1);
	if (ft_strncmp(&str[n - 4], ".fdf", 4))
		return (1);
	return (0);
}

void	ft_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit(1);
}
