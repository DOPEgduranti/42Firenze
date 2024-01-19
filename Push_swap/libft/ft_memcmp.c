/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:40:46 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/13 11:15:06 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	i = 0;
	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && t_s1[i] == t_s2[i])
		i++;
	return ((int)(t_s1[i] - t_s2[i]));
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
        const char s1[] = "0abcdefghij";
        const char s2[] = "abcdefgxyz";

        printf("corretto : %d\n", memcmp(s1, s2, 0));
        printf("mio : %d\n", ft_memcmp(s1, s2, 0));
        return(0);
}*/
