/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:39:11 by sangyeki          #+#    #+#             */
/*   Updated: 2022/03/15 12:42:56 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_2;
	unsigned char	*dst_2;

	if (!src && !dst)
		return (0);
	src_2 = (unsigned char *)src;
	dst_2 = (unsigned char *)dst;
	while (n)
	{
		*dst_2++ = *src_2++;
		n--;
	}
	return (dst);
}
