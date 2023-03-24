/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 03:43:42 by wwatik            #+#    #+#             */
/*   Updated: 2022/11/24 03:43:46 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*cpy;

	cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (free(s1), NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1)+ ft_strlen(s2) + 1));
	if (!s)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		s[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		s[i++] = s2[j++];
	}					
	s[i] = '\0';
	free (s1);
	return (s);
}

char	*ft_strchr(char *st, int n)
{
	if (!st)
		return (0);
	while (*st)
	{
		if (*st == (char)n)
			return (st);
		st++;
	}
	return (0);
}
