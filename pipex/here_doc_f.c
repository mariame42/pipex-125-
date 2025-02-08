/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:46 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 17:26:52 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	the_doc_family(t_here_doc *h, char **env)
{
	int		fd[2];
	int		status;
	int		id1;
	int		id2;

	if (pipe(fd) == -1)
		return (1);
	id1 = fork();
	if (id1 == -1)
		return (1);
	if (id1 == 0)
		child1(env, fd[1], h, fd);
	id2 = fork();
	if (id2 == 0)
		child2(env, fd[0], h, fd);
	free_here(h);
	close (fd[0]);
	close (fd[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, &status, 0);
	return (WEXITSTATUS(status));
}

void	child1(char **env, int fd_write, t_here_doc *h, int fd[2])
{
	int		file1;
	char	*path;

	close (fd[0]);
	if (fd_write == -1)
		doc_error("fd_write", h, fd);
	file1 = open("here_doc", O_RDONLY);
	if (file1 == -1)
		doc_error("file1", h, fd);
	if (dup2(fd_write, STDOUT_FILENO) == -1)
		doc_error("fd_write_dup", h, fd);
	if (dup2(file1, STDIN_FILENO) == -1)
		doc_error("file1_dup", h, fd);
	close(file1);
	close(fd_write);
	path = get_path(h->cmd, env);
	if (!path)
		doc_error("path", h, fd);
	execve(path, h->cmd_f, env);
	perror("Error in execve");
	free(path);
	exit(1);
}

void	child2(char **env, int fd_read, t_here_doc *h, int fd[2])
{
	int		file2;
	char	*path;

	close (fd[1]);
	if (fd_read == -1)
		doc_error("fd_read", h, fd);
	file2 = open(h->file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file2 == -1)
		doc_error("file2", h, fd);
	if (dup2(fd_read, STDIN_FILENO) == -1)
		doc_error("fd_read_dup", h, fd);
	if (dup2(file2, STDOUT_FILENO) == -1)
		doc_error("file2", h, fd);
	close(file2);
	close(fd_read);
	path = get_path(h->cmd1, env);
	if (!path)
		doc_error("path2", h, fd);
	execve(path, h->cmd1_f, env);
	perror("Error in execve");
	free(path);
	exit(1);
}
