/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:27:22 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/25 12:46:47 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_diner	*ft_dinernew(t_diner **diner, t_var *var)
{
	static int	tag = 1;
	t_diner		*lst;

	lst = malloc(sizeof(t_diner));
	if (ft_malloc_err(lst) == TRUE)
		ft_exit(diner, FALSE);
	lst->var = var;
	lst->tag = tag;
	lst->free_fork = FALSE;
	lst->death = FALSE;
	lst->meal_got = 0;
	lst->next = NULL;
	lst->ph_wait = 0;
	lst->nbr_of_philo = var->nbr_of_philo;
	lst->time_to_die = var->time_to_die;
	lst->time_to_eat = var->time_to_eat;
	lst->time_to_sleep = var->time_to_sleep;
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
	tofree_lst = *lst;
	while (counter)
	{
		//pthread_detach(*tofree_lst->id_philo);
		free(tofree_lst->id_philo);
		tofree_lst = tofree_lst->next;
		counter--;
	}
	pthread_mutex_destroy(&(*lst)->var->eat);
	pthread_mutex_destroy(&(*lst)->var->look);
	pthread_mutex_destroy(&(*lst)->var->print);
	pthread_mutex_destroy(&(*lst)->var->finish);
	counter = (*lst)->var->nbr_of_philo;
	free((*lst)->var);
	while (*lst && counter)
	{
		tofree_lst = *lst;
		*lst = (*lst)->next;
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
	if (*lst != new)
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
