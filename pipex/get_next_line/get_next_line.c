/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:59:34 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 11:55:14 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ready_for_next(char *line)
{
	char	*next;
	char	*ptr;
	int		len;

	ptr = ftt_strchr(line, '\n');
	if (!ptr)
	{
		return (free(line), line = NULL, NULL);
	}
	else
		len = (ptr - line) + 1;
	if (!line[len])
		return (free(line), line = NULL, NULL);
	next = ftt_strchr_allocation(line, len);
	free(line);
	if (!next)
		return (NULL);
	return (next);
}

char	*clean_line(char *line)
{
	char	*clean_line;

	if (!ftt_strchr(line, '\n'))
	{
		clean_line = ftt_strchar_rev(line, '\0');
		if (!clean_line)
			return (NULL);
		return (clean_line);
	}
	clean_line = ftt_strchar_rev(line, '\n');
	if (!clean_line)
		return (NULL);
	return (clean_line);
}

char	*read_line(char *line, int fd)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), line = NULL, NULL);
	buffer[0] = '\0';
	while (read_bytes > 0 && !ftt_strchr(line, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			line = ftt_strjoin(line, buffer);
		}
	}
	free(buffer);
	if (read_bytes < 0 || !line)
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*get_next_line(t_info *i)
{
	int			fd;
	static char	*line;
	char		*new_line;

	fd = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!line || (line && !ftt_strchr(line, '\n')))
		line = read_line(line, fd);
	if (!line)
		return (NULL);
	new_line = clean_line(line);
	if (!new_line || ftt_strlen(new_line) == 0)
		return (free(line), line = NULL, free(new_line), NULL);
	line = ready_for_next(line);
	i->len += ftt_strlen(new_line);
	return (new_line);
}

// int	main(void)
// {
// 	char *limit = "lolo";
// 	get_file(limit);
// }
