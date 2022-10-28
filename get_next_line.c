/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:20:46 by eballest          #+#    #+#             */
/*   Updated: 2022/10/28 18:48:29 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	i = 0;
	str = ft_read(str, &i, fd);
	if (!str)
		return (NULL);
	line = ft_newline(str, i);
	if (!line)
		return (NULL);
	str = ft_cleanline(str, i);
	if (!str)
		return (NULL);
	return (line);
}

char	*ft_read(char *str, int *i, int fd)
{
	int	j;

	while (ft_foundline(str, i) == -1)
	{
		str = ft_readline(str, fd, &j);
		if (j == 0)
			return (NULL);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_readline(char *str, int fd, int *j)
{
	char	line[BUFFER_SIZE + 1];

	if (read(fd, line, BUFFER_SIZE) <= 0)
	{
		free(str);
		return (NULL);
	}
	line[BUFFER_SIZE] = '\0';
	str = ft_addline(str, line);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_newline(char *str, int i)
{
	int		j;
	char	*line;

	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_cleanline(char *str, int i)
{
	char	*str2;
	int		j;

	str2 = (char *)malloc(ft_strlen(str) - i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (str[i] != '\0')
	{
		i++;
		str2[j] = str[i];
		j++;
	}
	str2[j] = '\0';
	free(str);
	return (str2);
}
