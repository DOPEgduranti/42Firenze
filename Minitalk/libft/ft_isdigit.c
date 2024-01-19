/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:52:18 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/09 11:27:05 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int     main(void)
{
        char    c = '0';

        printf("originale : %d\n", isdigit(c));
        printf("mio : %d\n", ft_isdigit(c));
        return (0);
}*/
