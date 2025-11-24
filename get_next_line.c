/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:41:46 by abegou            #+#    #+#             */
/*   Updated: 2025/11/24 19:36:16 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*stash;
	int			read_res;
	char		*temp;

	if (buffer)
	{
		if (ft_strchr(buffer, '\0') != 'NULL')
			return ;
		else if (ft_strchr(buffer, '\n') != 'NULL')
		{
			stash = ft_strjoin(, ft_strchr(buffer, '\n'))
		}
//			et join dans stash  -quand copie dans stash mettre ce qu'il y apres le \n aun debut du buffer (via une str tampon)
	}
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	read_res = read(fd, buffer, BUFFER_SIZE);
	while (read_res >= 0)
	{
		if (read_res < BUFFER_SIZE)
		ft_strchr(buffer, '\n') ft_strchr(buffer, '\0')
//		join jusquau \n dans stash
	}
	return (mangeur2merde);
}
