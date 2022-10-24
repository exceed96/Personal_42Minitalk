/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:41:03 by sangyeki          #+#    #+#             */
/*   Updated: 2022/03/15 12:42:45 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_a;
	unsigned char	*s2_a;

	if (!n || (!s1 && !s2))
		return (0);
	s1_a = (unsigned char *)s1;
	s2_a = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_a != *s2_a)
			return (*s1_a - *s2_a);
		s1_a++;
		s2_a++;
	}
	return (0);
}
