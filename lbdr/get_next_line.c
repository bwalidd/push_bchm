/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:09:37 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/17 02:11:31 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

char	*ft_del_line(char *buffer)
{
	char	*reserve;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (!buffer[count])
	{
		free(buffer);
		return (NULL);
	}
	reserve = malloc((ft_strlen(buffer) - count + 1) * sizeof(char));
	if (!reserve)
	{
		free(buffer);
		return (NULL);
	}		
	count++;
	while (buffer[count])
		reserve[i++] = buffer[count++];
	reserve[i] = 0;
	free(buffer);
	return (reserve);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;
	int		count;

	i = 0;
	count = 0;
	line = NULL;
	if (!(*buffer))
		return (NULL);
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (buffer[count] == '\0')
		line = ft_calloc(count + 1, sizeof(char));
	else if (buffer[count] == '\n')
		line = ft_calloc(count + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_fill_buf(int fd, char *reserve)
{
	char	*buffer;
	int		count;

	if (!reserve)
		reserve = ft_calloc(1, sizeof(char));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = 0;
		reserve = ft_strjoin(reserve, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_fill_buf(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_del_line(buf);
	return (line);
}
