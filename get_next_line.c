/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:41:46 by abegou            #+#    #+#             */
/*   Updated: 2025/11/23 20:39:48 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *buffer;
	char *mangeur2merde;
	int readres;
	int i;

	if (buffer)
	{
		if (ft_strchr(buffer, '\0') != 'NULL')
		else if (ft_strchr(buffer, '\n') != 'NULL')
			et join danws m2m  -quand copie dans m2m mettre ce kya apres le \n aun debut du buffer (via une str tampon)
	}
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	readres = read(fd, buffer, BUFFER_SIZE);
	while (readres >= 0)
	{
		regarder si read res < BUFFER_SIZE
		regarder dans le buffer si \n ou \0
		join jusquau \n dans m2m
	}
	return (mangeur2merde);
}
