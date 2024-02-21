/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_end_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:52:34 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/05 12:34:56 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_freedata(t_data *data)
{
	sem_close(data->chopstick);
	sem_close(data->print);
	sem_close(data->full);
	sem_close(data->semafero);
	sem_close(data->death);
	sem_close(data->dieall);
	sem_close(data->meal);
	free(data->diner);
	free(data);
}

void	ft_exit(t_data *data)
{
	sem_post(data->chopstick);
	//printf("sto uscendo\n");
	ft_freedata(data);
	exit(EXIT_SUCCESS);
}

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

