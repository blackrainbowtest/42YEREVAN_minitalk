/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:09:49 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/01 17:25:00 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize != 0)
	{
		while ((len < dstsize - 1) && src[len] != '\0')
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	return (ft_strlen(src));
}
