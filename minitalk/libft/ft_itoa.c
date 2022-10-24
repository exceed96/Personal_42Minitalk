/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:05:24 by sangyeki          #+#    #+#             */
/*   Updated: 2022/03/15 12:44:58 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(int num)
{
	int	count;

	count = 0;
	if (num < 0)
		count++;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	return (count + 1);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*n_str;

	len = len_n(n);
	n_str = malloc(sizeof(char) * len + 1);
	if (!n_str)
		return (0);
	n_str[len] = 0;
	if (!n)
		n_str[0] = '0';
	if (n < 0)
		n_str[0] = '-';
	while (n)
	{
		len--;
		if (n > 0)
			n_str[len] = n % 10 + '0';
		else
			n_str[len] = -(n % 10) + '0';
		n /= 10;
	}
	return (n_str);
}
