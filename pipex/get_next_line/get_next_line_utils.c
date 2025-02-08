/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:35:58 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 12:09:55 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ftt_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ftt_strchr_allocation(char *line, int len)
{
	char	*line_a;
	int		i;

	line_a = malloc(sizeof(char) * (ftt_strlen(line) - len + 1));
	if (!line_a)
		return (NULL);
	i = 0;
	while (line[len])
	{
		line_a[i++] = line[len++];
	}
	line_a[i] = '\0';
	return (line_a);
}

char	*ftt_strchar_rev(char *line, int c)
{
	char	*clean_line;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (c == '\n')
		clean_line = malloc(sizeof(char) * (i + 2));
	if (c == '\0')
		clean_line = malloc(sizeof(char) * (i + 1));
	if (!clean_line)
		return (NULL);
	if (line[i] == (char)c)
	{
		if ((char)c == '\n')
			clean_line[++i] = '\0';
		else
			clean_line[i] = '\0';
		while (--i >= 0)
			clean_line[i] = line[i];
		return (clean_line);
	}
	return (NULL);
}

char	*ftt_strjoin(char *line, char *buffer)
{
	char	*line2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line2 = malloc(sizeof(char) * (ftt_strlen(line) + ftt_strlen(buffer) + 1));
	if (!line2)
		return (free(line), NULL);
	while (line[i])
	{
		line2[i] = line[i];
		i++;
	}
	while (buffer[j])
		line2[i++] = buffer[j++];
	free(line);
	return (line2[i] = '\0', line2);
}

char	*ftt_strchr(char *line, int c)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == (char)c)
			return (&line[i]);
		i++;
	}
	return (NULL);
}
