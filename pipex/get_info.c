/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:05:46 by meid              #+#    #+#             */
/*   Updated: 2024/10/02 09:55:45 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_arr_cmd(char **av, int cmd_count)
{
	char	**arr_cmd;
	int		i;
	int		j;

	i = 0;
	j = 2;
	arr_cmd = malloc(sizeof(char *) * (cmd_count + 1));
	if (!arr_cmd)
		exit(1);
	while (i < cmd_count)
	{
		arr_cmd[i] = first_word(av[j]);
		j++;
		i++;
	}
	arr_cmd[i] = NULL;
	return (arr_cmd);
}

char	***get_arr_cmd_f(char **av, int cmd_count)
{
	char	***arr_cmd_f;
	int		i;
	int		j;

	arr_cmd_f = malloc(sizeof(char **) * (cmd_count + 1));
	if (!arr_cmd_f)
		exit(1);
	i = 0;
	j = 2;
	while (i < cmd_count)
	{
		arr_cmd_f[i] = ft_split(av[j], ' ');
		i++;
		j++;
	}
	arr_cmd_f[i] = NULL;
	return (arr_cmd_f);
}

char	***awk_arr_cmd_f(char **av, int cmd_count, t_fixed *f)
{
	int		i;
	int		j;
	char	***arr_cmd_f;
	char	*cmd;

	arr_cmd_f = malloc(sizeof(char **) * (cmd_count + 1));
	if (!arr_cmd_f)
		return (NULL);
	i = 0;
	j = 2;
	while (i < cmd_count)
	{
		cmd = first_word(av[j]);
		arr_cmd_f[i] = NULL;
		if (ft_strcmp("awk", cmd) == 0)
			arr_cmd_f[i] = split_awk(av[j], f);
		else
			arr_cmd_f[i] = ft_split(av[j], ' ');
		i++;
		free(cmd);
		j++;
	}
	arr_cmd_f[i] = NULL;
	return (arr_cmd_f);
}

int	free_array_ar(char ***array)
{
	int	i;
	int	j;

	i = 0;
	if (!array || !(*array))
		return (0);
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j] != NULL)
		{
			free(array[i][j]);
			j++;
		}
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
