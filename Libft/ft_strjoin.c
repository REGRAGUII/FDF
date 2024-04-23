/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:54:23 by yregragu          #+#    #+#             */
/*   Updated: 2024/04/21 18:00:54 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	size_t	len1;
	size_t	len2;

	str = NULL;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (s1 || s2)
	{
		str = malloc(sizeof(char) * (len1 + len2) + 1);
		if (!str)
			return (NULL);
		while (i < len1)
		{
			str[i] = s1[i];
			i++;
		}
		len2 = 0;
		while (i < (len1 + ft_strlen(s2)))
			str[i++] = s2[len2++];
		str[len1 + ft_strlen(s2)] = '\0';
	}
	return (str);
}
