/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:41:46 by abegou            #+#    #+#             */
/*   Updated: 2025/12/07 15:42:25 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	char	*line;
	
	line = ft_substr(stash, 0, ft_strlen(ft_strchr(stash, '\n')));
	return (line);
}

char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	char	*line;
	int		read_res;
	
	read_res = 1;
	buffer = ft_calloc(sizeof(char), (size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_res > 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_res] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			line = extract_line(stash);
			break ;
		}
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_stash(fd, stash);
	if (!stash || stash[0] == 0)
		return (NULL);
	return (stash);
}
