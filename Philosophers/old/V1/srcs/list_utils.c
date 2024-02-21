/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:27:22 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/17 11:42:26 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_diner	*ft_dinernew(t_table **table)
{
	static int	tag = 1;
	t_diner		*my_list;

	my_list = (t_diner *)malloc(sizeof(t_diner));
	if (!my_list)
		return (NULL);
	my_list->tag = tag;
	if (pthread_mutex_init(&my_list->id_fork, NULL) != FALSE)
	{
		write(2, "Error: mutex init failed", 24);
		ft_dinerclear(&(* table)->diner);
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&my_list->id_philo, NULL, ft_think, (void *)my_list) != FALSE)
	{
		write(2, "Error: thread can't be created", 30);
		ft_dinerclear(&(* table)->diner);
		exit(EXIT_FAILURE);
	}
	my_list->next = NULL;
	tag++;
	return (my_list);
}

void	ft_dinerclear(t_diner **lst)
{
	t_diner	*tofree_lst;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tofree_lst = *lst;
		*lst = (*lst)->next;
		pthread_detach(tofree_lst->id_philo);
		pthread_mutex_destroy(&tofree_lst->id_fork);
		free(tofree_lst);
	}
	lst = NULL;
}

void	ft_dineradd_back(t_diner **lst, t_diner *new)
{
	t_diner	*tmp_lst;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		tmp_lst = ft_dinerlast(lst);
		tmp_lst->next = new;
	}
}

void	ft_dineradd_last(t_diner **lst, t_diner *new)
{
	if (!new || !lst)
		return ;
	ft_dineradd_back(lst, new);
	new->next = *lst;
}

t_diner	*ft_dinerlast(t_diner **diner)
{
	t_diner	*lst;

	lst = *diner;
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
