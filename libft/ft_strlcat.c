/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:58:17 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/02 15:25:24 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (dlen >= dstsize)
		return (dstsize + slen);
	i = 0;
	while (dstsize > (dlen + i + 1) && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}
