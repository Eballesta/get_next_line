/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:45:13 by eballest          #+#    #+#             */
/*   Updated: 2022/10/28 17:57:14 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
static char	*coolfree(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}
*/

int	ft_foundLine(char *str, int*i)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == '\n')
			return (*i);
		*i = *i + 1;
	}
	return (-1);
}

char	*ft_addLine(char *str, char *line)
{
//	printf("entrem a add line\n");
	int		i;
	int		j;
	char	*newstr;

	i = ft_strlen(str);
//	printf("strlen %d, reservem %d\n", i, i + BUFFER_SIZE + 1);
	newstr = (char *)malloc(i + BUFFER_SIZE + 1);
//	printf("a la merda tot 2.0, newstr = %s\n", newstr);
	if (!newstr)
	{
//		printf("a la merda toooot\n");
		return (NULL);
	}
//	printf("abans dels while's\n");
	j = 0;
	while (j < i)
	{
		newstr[j] = str[j];
		j++;
	}
	j = 0;
	while (j < BUFFER_SIZE)
	{
		newstr[i] = line[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
//	printf("despres dels while's, newstr = %s\n", newstr);
//	printf("str abans del free = %s\n", str);
	free(str);
	return (newstr);
}
