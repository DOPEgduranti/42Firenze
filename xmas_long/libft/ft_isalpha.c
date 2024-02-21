/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:38:43 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/10 15:52:11 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1024);
	if (c >= 'a' && c <= 'z')
		return (1024);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int     main(void)
{
        char    c = 'Z';

        printf("originale : %d\n", isalpha(c));
        printf("mio : %d\n", ft_isalpha(c));
        return (0);
}*/
