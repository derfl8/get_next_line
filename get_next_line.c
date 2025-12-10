/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:41:46 by abegou            #+#    #+#             */
/*   Updated: 2025/12/10 09:12:55 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stash)
{
	char	*new_line;
	size_t	len;

	len = 0;
	new_line = ft_strchr(stash, '\n');
	if (new_line)
	{
		len = new_line - stash + 1;
		new_line = ft_substr(stash, 0, len);
	}
	return (new_line);
}

char	*read_stash(int fd, char *stash)
{
	char	*buffer;
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
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_stash(fd, stash);
	if (!stash || stash[0] == 0)
		return (NULL);
	line = extract_line(stash);
//	stash = update_stash(stash);
	return (stash);
}
