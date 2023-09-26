/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:27:45 by aherbet           #+#    #+#             */
/*   Updated: 2022/12/23 03:38:33 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*nxt_line(char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = ft_strlen((const char *)buffer) - i;
	tmp = ft_substr((const char *)buffer, i, j);
	return (free(buffer), tmp);
}

static char	*get_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, j, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_txt(int fd, char *buffer)
{
	char	*buf_txt;
	ssize_t	read_cnt;

	buf_txt = malloc((BUFFER_SIZE +1) * sizeof(char));
	if (!buf_txt)
		return (NULL);
	read_cnt = 1;
	while (read_cnt != 0 && !ft_strchr(buffer, '\n'))
	{
		read_cnt = read(fd, buf_txt, BUFFER_SIZE);
		if (read_cnt == -1)
			return (free(buf_txt), free(buffer), NULL);
		buf_txt[read_cnt] = '\0';
		buffer = ft_strjoin_free(buffer, buf_txt);
		if (buffer[0] == '\0')
			return (free(buf_txt), free(buffer), NULL);
	}
	return (free(buf_txt), buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_txt(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	if (!line)
		return (NULL);
	buffer[fd] = nxt_line(buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	return (line);
}
