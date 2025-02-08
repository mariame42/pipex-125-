/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:55:24 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 14:55:35 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**path_array(char **env)
{
	char	*path;
	char	**split;
	int		i;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break ;
		}
		i++;
	}
	if (!path)
		return (NULL);
	split = ft_split(path, ':');
	if (!split)
		return (NULL);
	return (split);
}

static char	*path_loop(char **split, char *cur, char *current, char *cmd)
{
	int	i;

	i = 0;
	while (split[i])
	{
		cur = ft_strjoin(split[i], "/");
		if (!cur)
			free_array(split);
		current = ft_strjoin(cur, cmd);
		free(cur);
		if (!current)
			free_array(split);
		if (access(current, X_OK) == 0)
		{
			free_array(split);
			return (current);
		}
		free(current);
		i++;
	}
	free_array(split);
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	*current;
	char	*cur;
	char	*res;
	char	**split;

	current = NULL;
	cur = NULL;
	res = NULL;
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	split = path_array(env);
	if (!split)
		return (NULL);
	res = path_loop(split, cur, current, cmd);
	return (res);
}
