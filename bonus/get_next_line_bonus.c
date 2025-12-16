/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:41:46 by abegou            #+#    #+#             */
/*   Updated: 2025/12/16 16:23:47 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*update_stash(char *stash)
{
	char	*new_stash;
	char	*pos;
	size_t	len;

	len = 0;
	pos = ft_strchr(stash, '\n');
	if (pos)
	{
		len = pos - stash + 1;
		new_stash = ft_substr(stash, len, ft_strlen(stash));
		free(stash);
		return (new_stash);
	}
	free(stash);
	return (NULL);
}

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
	else
		new_line = ft_substr(stash, 0, ft_strlen(stash));
	return (new_line);
}

char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		read_res;

	read_res = 1;
	buffer = ft_calloc(sizeof(char), (size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	while (read_res > 0)
	{
		read_res = read(fd, buffer, BUFFER_SIZE);
		if (read_res == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[read_res] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		free(temp);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_stash(fd, stash[fd]);
	if (!stash[fd] || stash[fd][0] == 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
