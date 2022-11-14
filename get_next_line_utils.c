/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:45:13 by eballest          #+#    #+#             */
/*   Updated: 2022/11/04 19:06:08 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

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

int	ft_foundline(char *str, unsigned int *i, int lread)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == '\n')
			return (*i);
		*i = *i + 1;
	}
	if ((lread < BUFFER_SIZE && lread > 0) || (lread == 0 && *i > 0))
	{
		return (*i);
	}
	return (-1);
}

char	*ft_addline(char *str, char *line, int lread)
{
	int		i;
	int		j;
	char	*newstr;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	newstr = (char *)malloc(i + lread + 1);
	if (!newstr)
		return (ft_free(&str));
	j = 0;
	while (j++ < i)
		newstr[j - 1] = str[j - 1];
	j = 0;
	while (j < lread)
	{
		newstr[i] = line[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	ft_free(&str);
	return (newstr);
}
