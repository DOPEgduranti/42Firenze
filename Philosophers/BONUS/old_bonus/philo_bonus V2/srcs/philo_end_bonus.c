/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_end_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:52:34 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/02 12:39:15 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void ft_wait(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while(i < data->var.nbr_of_philo)
	{
    	data->diner[i].finished_pid = waitpid(-1, &data->diner[i].status, 0);

        if (WIFEXITED(data->diner[i].status))
		{
			while (j < data->var.nbr_of_philo)
			{
				//kill(data->diner[j].pid, SIGTERM);
				j++;
			}
        }
		else
		{
            printf("Child process with PID %d has terminated abnormally.\n", data->diner[i].finished_pid);
        }
		i++;
	}
	i = 0;
}

void	ft_freedata(t_data *data)
{
	sem_close(data->chopstick);
	sem_close(data->print);
	sem_close(data->full);
	free(data->diner);
	free(data);
}