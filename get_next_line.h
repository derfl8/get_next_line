/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:12:03 by abegou            #+#    #+#             */
/*   Updated: 2025/11/18 22:12:28 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// libs
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

// custom functions
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s)
char	*ft_strjoin(char const *s1, char const *s2)
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size)

#endif
