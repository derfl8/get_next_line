/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:41:46 by abegou            #+#    #+#             */
/*   Updated: 2025/11/25 16:59:38 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
//	static char	*stash;
	int			read_res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	read_res = read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	do 
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free (line);
	}
	while(line != NULL);
	fd = close(fd);
	return (0);
}*/
