/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:18:27 by sangyeki          #+#    #+#             */
/*   Updated: 2022/03/15 12:41:16 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;
	char			*temp;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	temp = (char *)haystack;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (temp[i + j] && temp[i + j] == needle[j] && i + j < len)
		{
			if (!needle [j + 1])
				return (&temp[i]);
			j++;
		}
		i++;
	}
	return (0);
}
