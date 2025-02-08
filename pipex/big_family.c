/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_family.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:58:03 by meid              #+#    #+#             */
/*   Updated: 2024/10/01 14:49:33 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	make_big_family(t_fixed *f, t_dynamic *d, char **env)
{
	int	fd[MAX_FD][2];
	int	status;

	family_loops(fd, f, d, env);
	if (waitpid(d->pids[f->count - 1], &status, 0) == -1)
	{
		handle_error("waitpid", f, d, fd);
	}
	free_info(f, d);
	return (WEXITSTATUS(status));
}

void	family_loops(int fd[][2], t_fixed *f, t_dynamic *d, char **env)
{
	int	i;

	i = 0;
	while (i < f->pipe)
	{
		if (pipe(fd[i]) == -1)
			handle_error("pipe", f, d, fd);
		i++;
	}
	i = 0;
	while (i < f->count)
	{
		execute_children(f, d, env, fd);
		d->c_cmd += 1;
		i++;
	}
	close_all(fd, f);
	i = 0;
	while (i < f->count - 1)
	{
		if (waitpid(d->pids[i], NULL, 0) == -1)
			handle_error("waitpid", f, d, fd);
		i++;
	}
}

void	execute_children(t_fixed *f, t_dynamic *d, char **env, int fd[][2])
{
	char	*path;

	d->pids[d->c_cmd] = fork();
	if (d->pids[d->c_cmd] < 0)
		handle_error("fork", f, d, fd);
	if (d->pids[d->c_cmd] == 0)
	{
		close_unused_pipes(fd, f, d);
		if (d->c_cmd == f->cmd_1)
			d->f_fd[0] = file1(f, d, fd);
		else if (dup2(fd[d->c_cmd - 1][0], STDIN_FILENO) == -1)
			handle_error("1/dup2", f, d, fd);
		if (d->c_cmd == f->cmd_l)
			d->f_fd[1] = file2(f, d, fd);
		else if (dup2(fd[d->c_cmd][1], STDOUT_FILENO) == -1)
			handle_error("2/dup2", f, d, fd);
		path = get_path(f->cmd[d->c_cmd], env);
		if (!path)
			handle_error("path", f, d, fd);
		close_used_pipes(fd, f, d);
		execve(path, f->cmd_f[d->c_cmd], env);
		free(path);
		handle_error("execve", f, d, fd);
	}
	return ;
}

int	file1(t_fixed *f, t_dynamic *d, int fd[][2])
{
	int	file1;

	file1 = open(f->file1, O_RDONLY);
	if (file1 == -1)
		handle_error("file1", f, d, fd);
	if (dup2(file1, STDIN_FILENO) == -1)
		handle_error("file1_dup", f, d, fd);
	close(file1);
	return (file1);
}

int	file2(t_fixed *f, t_dynamic *d, int fd[][2])
{
	int	file2;

	file2 = open(f->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		handle_error("file2", f, d, fd);
	if (dup2(file2, STDOUT_FILENO) == -1)
		handle_error("file2_dup", f, d, fd);
	close(file2);
	return (file2);
}
