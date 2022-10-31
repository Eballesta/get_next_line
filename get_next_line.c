/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:20:46 by eballest          #+#    #+#             */
/*   Updated: 2022/10/31 15:17:50 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*str = NULL;
	char			*line;
	unsigned int	i;
	int				lread;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!str)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	i = 0;
	str = ft_read(str, &i, fd, &lread);
	if (!str)
		return (NULL);
	line = ft_newline(str, i, lread);
	if (!line)
		return (NULL);
	str = ft_cleanline(str, i);
	if (!str)
		return (NULL);
	return (line);
}

char	*ft_read(char *str, unsigned int *i, int fd, int *lread)
{
	while (ft_foundline(str, i) == -1)
	{
		str = ft_readline(str, fd, lread);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_readline(char *str, int fd, int *lread)
{
	char	line[BUFFER_SIZE + 1];

	*lread = read(fd, line, BUFFER_SIZE);
	if (*lread <= 0)
	{
		free(str);
		return (NULL);
	}
	line[*lread] = '\0';
	str = ft_addline(str, line, *lread);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_newline(char *str, unsigned int i, int lread)
{
	unsigned int	j;
	char			*line;

	if (str[i] == '\n' || lread < 0)
		line = (char *)malloc(i + 2);
	else
		line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_cleanline(char *str, unsigned int i)
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
