/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:21:27 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/05 21:23:51 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	stepcount;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	stepcount = 0;
	if (start < strlen)
		stepcount = strlen - start;
	if (stepcount > len)
		stepcount = len;
	if (start >= strlen)
		return (ft_calloc(1, sizeof(char)));
	substr = (char *)ft_calloc((stepcount + 1), sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, stepcount + 1);
	return (substr);
}
/*
int	main()
{
	ft_substr("", 1, 1);
	return (0);
}*/
