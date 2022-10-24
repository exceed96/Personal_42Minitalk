/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:02:07 by sangyeki          #+#    #+#             */
/*   Updated: 2022/03/15 13:56:26 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*n_list;

	n_list = *lst;
	while (n_list)
	{
		temp = n_list->next;
		ft_lstdelone(n_list, del);
		n_list = temp;
	}
	*lst = 0;
}
