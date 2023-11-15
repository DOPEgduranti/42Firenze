/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:51:53 by gduranti          #+#    #+#             */
/*   Updated: 2023/11/06 09:56:10 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readbuff(char *sta_str, int fd)
{
	char	*buff_str;
	int		l_buff;

	buff_str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff_str)
		return (NULL);
	l_buff = 1;
	while (l_buff > 0 && ft_feedline(sta_str) == FALSE)
	{
		l_buff = read(fd, buff_str, BUFFER_SIZE);
		if (l_buff == -1)
		{
			free(sta_str);
			free(buff_str);
			return (NULL);
		}
		buff_str[l_buff] = '\0';
		sta_str = ft_strjoin(sta_str, buff_str);
	}
	free(buff_str);
	return (sta_str);
}

char	*ft_dstset(char *sta_str)
{
	char	*dst;
	int		i;

	i = 0;
	if (!sta_str[i])
		return (NULL);
	while (sta_str[i] && sta_str[i] != '\n')
		i++;
	dst = ft_calloc((i + 2), sizeof(char));
	if (!dst)
		return (0);
	i = 0;
	while (sta_str[i] && sta_str[i] != '\n')
	{
		dst[i] = sta_str[i];
		i++;
	}
	if (sta_str[i] == '\n')
	{
		dst[i] = sta_str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_stastrset(char *sta_str)
{
	int		i;
	int		j;
	char	*returnline;

	i = 0;
	while (sta_str[i] && sta_str[i] != '\n')
		i++;
	if (!sta_str[i])
	{
		free(sta_str);
		return (NULL);
	}
	returnline = ft_calloc((ft_strlen(sta_str) - i + 1), sizeof(char));
	if (!returnline)
		return (0);
	i++;
	j = 0;
	while (sta_str[i])
		returnline[j++] = sta_str[i++];
	returnline[j] = '\0';
	free(sta_str);
	return (returnline);
}

char	*get_next_line(int fd)
{
	static char	*sta_str = NULL;
	char		*dst;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	sta_str = ft_readbuff(sta_str, fd);
	if (!sta_str)
		return (NULL);
	dst = ft_dstset(sta_str);
	sta_str = ft_stastrset(sta_str);
	return (dst);
}

/*int	main(void)
{
	int		fd1;
​
	fd1 = open("ex0.txt", O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
​
		printf("%s\n", get_next_line(fd1));
		printf("%s\n", get_next_line(fd1));
		printf("%s\n", get_next_line(fd1));
		printf("%s\n", get_next_line(fd1));
		printf("%s\n", get_next_line(fd1));
		printf("%s\n", get_next_line(fd1));
	close(fd1);
	return (0);
}*/