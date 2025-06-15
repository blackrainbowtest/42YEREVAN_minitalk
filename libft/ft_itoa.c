/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 19:12:34 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/07 20:03:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_convert_to_str(char *str, size_t len, unsigned int num)
{
	while (num > 0)
	{
		str[--len] = ((num % 10) + 48);
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	len = ft_num_len(n);
	str = (char *)ft_calloc(len + 1, (sizeof(char)));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = n * -1;
	}
	else
		num = n;
	str = ft_convert_to_str(str, len, num);
	return (str);
}
