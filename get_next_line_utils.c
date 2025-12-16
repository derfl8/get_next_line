/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:21:10 by abegou            #+#    #+#             */
/*   Updated: 2025/12/16 16:33:24 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		j;
	int		i;
	int		k;

	i = ft_strlen(s1);
	k = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	ret = ft_calloc(sizeof(char), i + k + 1);
	if (!ret)
		return (NULL);
	j = -1;
	while (++j < i)
		ret[j] = s1[j];
	ret[j] = '\0';
	j = -1;
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	new = ft_calloc(sizeof(char), (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*str;
	size_t			i;

	if (size != 0 && nmemb != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	str = (unsigned char *)ptr;
	i = 0;
	while (i < (nmemb * size))
		str[i++] = '\0';
	return (ptr);
}
