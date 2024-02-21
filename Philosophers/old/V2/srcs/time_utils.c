/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:30:59 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 11:07:41 by gduranti         ###   ########.fr       */
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

void	ft_usleep(__suseconds_t usec)
{
	usleep(usec);
}
