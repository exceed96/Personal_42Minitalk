/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:23:40 by sangyeki          #+#    #+#             */
/*   Updated: 2022/03/15 12:42:07 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_2;
	unsigned char	*src_2;

	if (!dst && !src)
		return (0);
	dst_2 = (unsigned char *)dst;
	src_2 = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			dst_2[len - 1] = src_2[len - 1];
			len--;
		}
	}
	return (dst);
}
