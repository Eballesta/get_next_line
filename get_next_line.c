/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:20:46 by eballest          #+#    #+#             */
/*   Updated: 2022/10/28 17:56:09 by eballest         ###   ########.fr       */
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
//	printf("en entrar, str = %s\n", str);
	if (!str)
	{
		str = (char *)malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
//	printf("despres de evitar que no sigui null str = %s\n", str);
	i = 0;
	while (ft_foundLine(str, &i) == -1)
	{
//		printf("a dins el while de foundline str = %s\n", str);
		str = ft_readLine(str, fd);
		if (!str)
			return (NULL);
	}
//	printf("despres del while str = %s\n", str);
	line = ft_newLine(str, i);
	if (!line)
		return (NULL);
//	printf("la liea es linea = %s\n", line);
	str = ft_cleanLine(str, i);
//	printf("despres de buidar la linea str = %s\n", str);
	if (!str)
		return (NULL);
	return (line);
}

char	*ft_readLine(char *str, int fd)
{
//	printf("a read line\n");
	char	line[BUFFER_SIZE + 1];

	if (read(fd, line, BUFFER_SIZE) <= 0)
	{
		free(str);
		return (NULL);
	}
//	printf("despres del read line = %s\n", line);
	line[BUFFER_SIZE] = '\0';
//	printf("falla l'add line\n");
	str = ft_addLine(str, line);
	if (!str)
		return (NULL);
//	printf("despres d'afegir linea str = %s\n", str);
	return (str);
}

char	*ft_newLine(char *str, int i)
{
	int	j;
	char	*line;

//	printf("Inici del new line i=%d\n", i);
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
//	printf("    Line= %s\n", line);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
//	printf("     Line2=%s\n", line);
	line[j] = '\0';
	return (line);
}

char	*ft_cleanLine(char *str, int i)
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
