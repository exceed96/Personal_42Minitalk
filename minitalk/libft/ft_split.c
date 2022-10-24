/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:26:30 by sangyeki          #+#    #+#             */
/*   Updated: 2022/03/15 13:13:53 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_func(char **str)
{	
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
	return (0);
}

static size_t	word_count(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*str_put(char *s, char c)
{
	size_t	len;
	char	*str;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	count_m;

	if (!s)
		return (0);
	count_m = word_count((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (count_m + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < count_m)
	{
		while (*s == c)
			s++;
		str[i] = str_put((char *)s, c);
		if (!str[i])
			return (free_func(str));
		s += ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
