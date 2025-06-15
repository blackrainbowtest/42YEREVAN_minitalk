/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:24:52 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/03 19:40:19 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1tmp;
	const unsigned char	*s2tmp;

	s1tmp = (const unsigned char *)s1;
	s2tmp = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*s1tmp != *s2tmp)
			return ((int)(*s1tmp - *s2tmp));
		s1tmp++;
		s2tmp++;
		n--;
	}
	return (0);
}
