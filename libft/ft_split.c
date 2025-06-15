/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:31:26 by aramarak          #+#    #+#             */
/*   Updated: 2025/02/07 21:08:41 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **split)
{
	size_t	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static size_t	ft_word_count(const char *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word_count);
}

static char	**ft_dynamic_add(const char *s, char **split_arr,
		size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (split_arr[i])
		i++;
	split_arr[i] = ft_substr(s, start, len);
	if (!split_arr[i])
	{
		return (ft_free(split_arr));
	}
	return (split_arr);
}

static char	**ft_dynamic_array(const char *s, char c, char **split_arr)
{
	size_t		start;
	size_t		end;
	const char	*stmp;

	start = 0;
	stmp = s;
	while (*s)
	{
		while (*s && *s == c && ++start)
			s++;
		if (!*s)
			return (split_arr);
		end = start;
		while (*s && *s != c)
		{
			end++;
			s++;
		}
		if (!ft_dynamic_add(stmp, split_arr, start, end - start))
			return (NULL);
		start = end;
	}
	return (split_arr);
}

char	**ft_split(const char *s, char c)
{
	char	**split_arr;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	split_arr = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!split_arr)
		return (NULL);
	split_arr[word_count] = NULL;
	split_arr = ft_dynamic_array(s, c, split_arr);
	if (!split_arr)
		return (NULL);
	return (split_arr);
}
