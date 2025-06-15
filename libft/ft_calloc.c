/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:12:58 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/05 20:37:36 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*arr;

	if (num != 0 && (size_t) - 1 / num < size)
		return (NULL);
	arr = (void *)malloc(size * num);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * num);
	return (arr);
}
