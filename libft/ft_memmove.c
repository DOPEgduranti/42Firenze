/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:37:29 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/11 12:23:49 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*un_dest;
	unsigned char	*un_src;
	long int		i;

	un_dest = (unsigned char *)dest;
	un_src = (unsigned char *)src;
	i = -1;
	if (dest == src)
		return (dest);
	if (un_dest < un_src)
	{
		while (++i < (long int)n)
			un_dest[i] = un_src[i];
	}
	else
	{
		while (n > 0)
		{
			un_dest[n - 1] = un_src[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	char    c[] = "bella ciao !";
	char    d0[50];
	char    d1[50];

        memmove(d0, c, 8);
        ft_memmove(d1, c, 8);
        printf("originale : %s\n", d0);
        printf("mio : %s\n", d1);
        return (0);
}*/
