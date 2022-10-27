/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:45:52 by eballest          #+#    #+#             */
/*   Updated: 2022/10/27 18:46:01 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_foundLine(char *str, int *i);
char	*ft_readLine(char *str, int fd);
char	*ft_newLine(char *str, int i);
char	*ft_cleanLine(char *str, int i);
int		ft_strlen(char *str);
char	*ft_addLine(char *str, char *line);

#endif
