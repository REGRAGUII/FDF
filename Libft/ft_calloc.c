/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:02:36 by yregragu          #+#    #+#             */
/*   Updated: 2024/08/01 12:47:13 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*x;

	if (size != 0 && 4294967295 / size < nmemb)
		return (0);
	x = malloc(size * nmemb);
	if (!x)
		return (0);
	ft_bzero(x, size * nmemb);
	return (x);
}
