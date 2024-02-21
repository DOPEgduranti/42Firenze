/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:24 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/16 15:30:30 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_malloc_err(void *ptr)
{
	if (!ptr)
	{
		write(2, "Error: Unexpected malloc behaviour", 34);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_argc_err(int argc)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: Wrong input", 18);
		return (TRUE);
	}
	return (FALSE);
}
