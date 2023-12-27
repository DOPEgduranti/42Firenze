/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:02:26 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/16 15:59:02 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = (char *)s;
	i = 0;
	while (res[i])
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	if (res[i] == (unsigned char)c)
		return (&res[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	const char str[] = "mamma mia bella ciao !";
	const char ch = '\0';
	
	printf("String after |%c| is - |%s|\n", ch, strchr(str, ch));
	printf("String after |%c| is - |%s|\n", ch, ft_strchr(str, ch));
	printf("%p\n", strchr("teste", 'e'));
	printf("%p\n", ft_strchr("teste", 'e'));
	return(0);
}*/
