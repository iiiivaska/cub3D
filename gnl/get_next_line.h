/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:18 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 20:53:23 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *string);
char	*ft_strjoin_gnl(char *str1, char *str2);
int		find_nl(char *str);

#endif
