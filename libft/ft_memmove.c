/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:28:17 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/01 16:54:44 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dtmp;
	const unsigned char	*stmp;

	if (!dest && !src)
		return (NULL);
	dtmp = (unsigned char *)dest;
	stmp = (const unsigned char *)src;
	if (dtmp < stmp)
		while (n--)
			*(dtmp++) = *(stmp++);
	else
	{
		dtmp += n - 1;
		stmp += n - 1;
		while (n--)
			*(dtmp--) = *(stmp--);
	}
	return (dest);
}
