/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:27:22 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 15:49:28 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_diner	*ft_dinernew(t_diner **diner, t_var *var)
{
	static int	tag = 1;
	t_diner		*lst;

	lst = malloc(sizeof(t_diner));
	if (!lst)
		return (NULL);
	lst->var = var;
	lst->tag = tag;
	lst->free_fork = TRUE;
	lst->meal_got = 0;
	if (ft_muterr(pthread_mutex_init(&lst->id_fork, NULL), diner) == TRUE)
		ft_exit(diner, FALSE);
	pthread_mutex_lock(&lst->id_fork);
	lst->next = NULL;
	tag++;
	return (lst);
}

void	ft_dinerclear(t_diner **lst)
{
	t_diner	*tofree_lst;
	int		counter;

	if (!lst || !*lst)
		return ;
	counter = (*lst)->var->nbr_of_philo;
	while (*lst && counter)
	{
		pthread_detach((*lst)->id_philo);
		*lst = (*lst)->next;
		counter--;
	}
	counter = (*lst)->var->nbr_of_philo;
	free((*lst)->var);
	while (*lst && counter)
	{
		tofree_lst = *lst;
		*lst = (*lst)->next;
		if (tofree_lst->id_fork.__data.__lock == TRUE)
			pthread_mutex_unlock(&tofree_lst->id_fork);
		pthread_mutex_destroy(&tofree_lst->id_fork);
		//free((void *)tofree_lst->id_philo);
		free(tofree_lst);
		counter--;
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
