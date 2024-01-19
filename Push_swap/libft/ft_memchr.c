/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:03:04 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/13 12:30:47 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*un_s;
	unsigned char	un_c;
	size_t			i;

	if (!s && n == 0)
		return (NULL);
	un_s = (unsigned char *)s;
	un_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (un_s[i] == un_c)
			return ((void *)&un_s[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
        const char str[] = "mamma mia bella ciao !";
        const char ch = '8';

        printf("String after |%c| is - |%s|\n", ch,
			(char *)memchr(str, ch, 5));
        printf("String after |%c| is - |%s|\n", ch,
			(char *)ft_memchr(str, ch, 5));
        return(0);
}*/
