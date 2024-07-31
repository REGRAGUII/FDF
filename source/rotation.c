/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:26:03 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/30 13:24:04 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float rad(float deg)
{
	return(deg * PI / 180);
}

void	rotate_z(t_2dcoord *dim, float x, float y,int angle)
{
	dim->x1 = (x * cos(rad(angle)) - y * sin(rad(angle)));
	dim->y1 = (x * sin(rad(angle)) + y * cos(rad(angle)));

}

void	rotate_x(t_2dcoord *dim, float y, float z, int angle)
{
	// dim->x1 = (y * cos(rad(angle)) - z * sin(rad(angle)));
	dim->y1 = (y * sin(rad(angle)) + z * cos(rad(angle)));
}



void	rotate_y(t_2dcoord *dim, int x, int z, int angle)
{
    dim->x1 = (x * cos(rad(angle)) + z * sin(rad(angle)));
    dim->y1 = (z * cos(rad(angle) - x * sin(rad(angle))));
}