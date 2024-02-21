/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:26:20 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/17 11:43:32 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eat()
{
	
}

void	*ft_think(void *table)
{
	t_diner *table1;
	static int	i = 1;

	table1 = (t_diner *)table;
	pthread_mutex_lock(&table1->id_fork);
	printf("counter : %d\n", i++);
	printf("philo[%d] : %lu\n\n", table1->tag, table1->id_philo);
	printf("mutex[%u] : %d\n\n", i, table1->diner->id_fork);
	pthread_mutex_unlock(&table1->id_fork);
	return (NULL);
}
