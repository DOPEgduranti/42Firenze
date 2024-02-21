/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:13 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/13 13:09:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	i = 0;
	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (un_s1[i] && un_s2[i] && i < n - 1 && un_s1[i] == un_s2[i])
		i++;
	return ((int)(un_s1[i] - un_s2[i]));
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
        const char s1[] = "mamma mia bella ciao !";
        const char s2[] = "mamma mia bella ciao !";

        printf("corretto : %d\n", strncmp(s1, s2, 30));
        printf("mio : %d\n", ft_strncmp(s1, s2, 30));
        return(0);
}*/
