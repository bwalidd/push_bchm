/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:10:11 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/17 02:11:38 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;

	c1 = (char)c;
	i = 0;
	while (*s != '\0' && *s != c1)
		s++;
	if (*s == c1)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*resulttab;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	resulttab = malloc((size + 1) * 1);
	if (!resulttab)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		resulttab[i++] = s1[j++];
	j = 0;
	while (s2[j])
		resulttab[i++] = s2[j++];
	resulttab[i] = 0;
	free(s1);
	return (resulttab);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;	

	tab = NULL;
	if (size && count > UINT_MAX / size)
		return (tab);
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*d;

	i = 0;
	d = (char *)s;
	while (i < n)
	{
		*d++ = '\0';
		i++;
	}
}
