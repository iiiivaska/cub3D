/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:22:23 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 20:53:16 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char **line, char *temp)
{
	int	line_size;
	int	i;

	if (!temp)
		return (0);
	i = 0;
	line_size = 0;
	while (temp[line_size] != '\0' && temp[line_size] != '\n')
		line_size++;
	*line = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!(*line))
		return (-1);
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		(*line)[i] = temp[i];
		i++;
	}
	(*line)[i] = '\0';
	return (0);
}

int	cut_line(char **temp)
{
	char	*temp2;
	int		sz;
	int		i;

	sz = 0;
	while ((*temp)[sz] != '\0' && (*temp)[sz] != '\n')
		sz++;
	if ((*temp)[sz] == '\0')
	{
		free((void *)*temp);
		*temp = 0;
		return (0);
	}
	temp2 = (char *)malloc(sizeof(char) * (ft_strlen(*temp) - sz + 1));
	if (!temp2)
	{
		return (-1);
	}
	i = 0;
	while ((*temp)[++sz])
		temp2[i++] = (*temp)[sz];
	temp2[i] = '\0';
	free((void *)(*temp));
	*temp = temp2;
	return (0);
}

int	free_tb(char **temp, char **buffer)
{
	free((void *)*temp);
	free((void *)*buffer);
	return (1);
}

int	gnl(int fd, char **line, int rc, char *buffer)
{
	static char	*temp;

	while ((rc != 0) && find_nl(temp))
	{
		rc = read(fd, buffer, BUFFER_SIZE);
		if (rc == -1)
		{
			free_tb(&temp, &buffer);
			return (-1);
		}
		buffer[rc] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
	}
	free(buffer);
	if (get_line(line, temp) == -1 || cut_line(&temp) == -1)
	{
		free(temp);
		return (-1);
	}
	if (rc == 0)
	{
		free(temp);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	int			rc;
	int			k;

	rc = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE <= 0
		|| !buffer)
		return (-1);
	k = gnl(fd, line, rc, buffer);
	if (k == -1)
		return (-1);
	if (k == 0)
		return (0);
	return (1);
}
