/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:34:44 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/01 13:13:48 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = ft_datagen(argc, argv);
	ft_philo_gen(data);
	ft_wait(data);
	return (0);
}









// int ft_test(int argc, char **argv)
// {
// 	(void)argc;
// 	(void **)argv;
	
// 	int	i = 0;
// 	int	j = 0;
// 	int pippo;
// 	pid_t	philo[2];
// 	int status[2];
//     pid_t finished_pid[2];
	
// 	while(i < 2)
// 	{
// 		philo[i] = fork();
// 		if (philo[i] == -1)
// 		{
// 			printf("error");
// 			exit(EXIT_FAILURE);
// 		}
// 		else if (philo[i] == 0)
// 		{
// 			printf("philo[%d] is asleep\n", i);
// 			if(i % 2 == 0)
// 				sleep(4);
// 			if(i % 2 == 1)
// 				sleep(100);
// 			printf("philo[%d] is awake\n", i);
// 			exit(0);
// 		}
// 		printf("philo[%d] = %d\n", i, philo[i]);
// 		// printf("%d\n",getpid());
// 		i++;
// 	}
// 	printf("%d\n",getpid());
// 	// sleep(4);
// 	// kill(philo[0], SIGINT);
// 	// sleep(4);
// 	// kill(philo[1], SIGINT);
// 	i = 0;
// 	while(i < 2)
// 	{
//     	finished_pid[i] = waitpid(-1, &status[i], 0);

//         if (WIFEXITED(status[i]))
// 		{
// 			while (j < 2)
// 			{
// 				kill(philo[j], SIGINT);
// 				j++;
// 			}
// 			printf("status %d\n", status[i]);
//             printf("Child process with PID %d has finished.\n", finished_pid[i]);
//         }
// 		else
// 		{
//             printf("Child process with PID %d has terminated abnormally.\n", finished_pid[i]);
//         }
// 		i++;
// 	}
// 	return (0);
// }