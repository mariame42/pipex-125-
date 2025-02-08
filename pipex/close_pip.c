/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:54:24 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 17:27:45 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_unused_pipes(int fd[][2], t_fixed *f, t_dynamic *d)
{
	int	i;
	int	j;
	int	pipe_count;
	int	cmd_number;
	int	last_cmd_num;

	i = 1;
	j = 0;
	pipe_count = f->pipe;
	cmd_number = d->c_cmd + 1;
	last_cmd_num = f->cmd_l + 1;
	while (j < pipe_count)
	{
		if (!(cmd_number - 2 == j) && !((i == last_cmd_num)
				&& cmd_number == last_cmd_num))
			close(fd[j][0]);
		if (!(cmd_number - 1 == j) && !((i == 1) && cmd_number == 1))
			close(fd[j][1]);
		i++;
		j++;
	}
	return (0);
}

int	close_used_pipes(int fd[][2], t_fixed *f, t_dynamic *d)
{
	int	i;
	int	j;
	int	pipe_count;
	int	cmd_number;
	int	last_cmd_num;

	i = 1;
	j = 0;
	pipe_count = f->pipe;
	cmd_number = d->c_cmd + 1;
	last_cmd_num = f->cmd_l + 1;
	while (j < pipe_count)
	{
		if ((cmd_number - 2 == j) || ((i == last_cmd_num)
				&& cmd_number == last_cmd_num))
			close(fd[j][0]);
		if ((cmd_number - 1 == j) || ((i == 1) && cmd_number == 1))
			close(fd[j][1]);
		i++;
		j++;
	}
	return (0);
}

int	close_all(int fd[][2], t_fixed *f)
{
	int	i;
	int	pipe_count;

	i = 0;
	pipe_count = f->pipe;
	while (i < pipe_count)
	{
		if (fd[i][0] != '\0')
			close(fd[i][0]);
		if (fd[i][1] != '\0')
			close(fd[i][1]);
		i++;
	}
	return (0);
}
