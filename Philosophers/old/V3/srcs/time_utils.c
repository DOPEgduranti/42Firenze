/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:30:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 12:34:38 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void ft_usleep(long usec)
// {
//  struct timeval	start;
// 	struct timeval	current;
    
// 	gettimeofday(&start, NULL);
// 	gettimeofday(&current, NULL);
// 	while (current.tv_usec - start.tv_usec < usec)
// 	{
// 		usleep(1);
// 		gettimeofday(&current, NULL);
// 	}
// }
// void ft_usleep(long usec)
// {
//  	struct timeval	current;
// 	__suseconds_t	time;

// 	gettimeofday(&current, NULL);
// 	time = current.tv_usec;
// 	while (current.tv_usec - time < usec)
// 	{
// 		gettimeofday(&current, NULL);
// 	}
// }

long get_elapsed_time_microseconds(struct timeval start, struct timeval end)
{
    return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

void ft_usleep(long usec) {
    struct timeval start, current;
    long elapsed;
    long rem;

    start.tv_usec = 0;
    start.tv_sec = 0;
	gettimeofday(&start, NULL);
    do {
        gettimeofday(&current, NULL);
        elapsed = get_elapsed_time_microseconds(start, current);
        rem = usec - elapsed;

        if (rem > 1000) 
            usleep(rem / 2);
        
    } while (elapsed < usec);
}
