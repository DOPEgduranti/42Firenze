/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:47:39 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/16 11:28:18 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp_lst;

	size = 1;
	tmp_lst = lst;
	if (!lst)
		return (0);
	while (tmp_lst->next)
	{
		tmp_lst = tmp_lst->next;
		size++;
	}
	return (size);
}
