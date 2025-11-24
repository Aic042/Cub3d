/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbolivar <sbolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:06:26 by aingunza          #+#    #+#             */
/*   Updated: 2025/11/21 19:41:59 by sbolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_free(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free (s1);
	return (temp);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int		num_line;

	if (!res)
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(res), NULL);
	num_line = read(fd, buffer, BUFFER_SIZE);
	while (num_line > 0)
	{
		buffer[num_line] = 0;
		res = ft_join_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		num_line = read(fd, buffer, BUFFER_SIZE);
	}
	if (num_line == -1)
		return (free(res), free(buffer), NULL);
	free (buffer);
	return (res);
}

char	*ft_first_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	char	*next;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!next)
	{
		free (buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	next[j] = '\0';
	free (buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_first_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
