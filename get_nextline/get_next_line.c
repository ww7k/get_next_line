/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:43:15 by wwatik            #+#    #+#             */
/*   Updated: 2022/11/24 03:43:24 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*ft_read(int fd, char *st)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(st), NULL);
	while (i != 0 && !ft_strchr(st, '\n'))
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (buffer);
			free(st);
			return (NULL);
		}
		buffer[i] = '\0';
		st = ft_strjoin(st, buffer);
		if (!st)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (st);
}

char	*ft_current_line(char *st)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!st)
		return (NULL);
	while (st[i] && st[i] != '\n')
		i++;
	if (st[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (st[i] != '\n' && st[i])
	{
		line[i] = st[i];
		i++;
	}
	if (st[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *st)
{
	size_t	i;
	size_t	j;
	char	*nl;

	i = 0;
	j = 0;
	if (!st)
		return (NULL);
	while (st[i] != '\n' && st[i])
		i++;
	if (!st[i])
		return (free(st), NULL);
	nl = malloc(sizeof(char) * (ft_strlen(st) - i + 1));
	if (!nl)
		return (free(st), NULL);
	i++;
	while (st[i])
	{
		nl[j] = st[i];
		i++;
		j++;
	}
	nl[j] = '\0';
	free (st);
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*st;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st = ft_read(fd, st);
	if (!st)
		return (NULL);
	if (!st[0])
	{
		free(st);
		st = NULL;
		return (NULL);
	}
	ln = ft_current_line(st);
	if (!ln)
	{
		free(st);
		st = NULL;
		return (NULL);
	}
	st = ft_next_line(st);
	return (ln);
}
