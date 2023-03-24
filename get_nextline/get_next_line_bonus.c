/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:43:27 by wwatik            #+#    #+#             */
/*   Updated: 2023/01/24 05:43:30 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line_bonus.h"

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
	static char	*st[OPEN_MAX];
	char		*ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st[fd] = ft_read(fd, st[fd]);
	if (!st[fd])
		return (NULL);
	if (!st[fd][0])
	{
		free(st[fd]);
		st[fd] = NULL;
		return (NULL);
	}
	ln = ft_current_line(st[fd]);
	if (!ln)
	{
		free(st[fd]);
		st[fd] = NULL;
		return (NULL);
	}
	st[fd] = ft_next_line(st[fd]);
	return (ln);
}
