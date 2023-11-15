/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:31:56 by gduranti          #+#    #+#             */
/*   Updated: 2023/11/06 12:12:15 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(size * nmemb);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

t_bool	ft_feedline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (FALSE);
	while (s[i])
	{
		if (s[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*ft_strjoin(char *sta_str, char *buff)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!buff)
		return (NULL);
	if (!sta_str)
		sta_str = ft_calloc(1, sizeof(char));
	if (!sta_str)
		return (NULL);
	res = ft_calloc((ft_strlen(sta_str) + ft_strlen(buff) + 1), sizeof(char));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	if (sta_str)
		while (sta_str[++i] != '\0')
			res[i] = sta_str[i];
	while (buff[j] != '\0')
		res[i++] = buff[j++];
	res[ft_strlen(sta_str) + ft_strlen(buff)] = '\0';
	free(sta_str);
	return (res);
}
