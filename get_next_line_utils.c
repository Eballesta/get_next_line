/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:45:13 by eballest          #+#    #+#             */
/*   Updated: 2022/10/28 18:42:14 by eballest         ###   ########.fr       */
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

int	ft_foundline(char *str, int*i)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == '\n')
			return (*i);
		*i = *i + 1;
	}
	return (-1);
}

char	*ft_addline(char *str, char *line)
{
	int		i;
	int		j;
	char	*newstr;

	i = ft_strlen(str);
	newstr = (char *)malloc(i + BUFFER_SIZE + 1);
	if (!newstr)
		return (NULL);
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
	free(str);
	return (newstr);
}
