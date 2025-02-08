/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:53:17 by meid              #+#    #+#             */
/*   Updated: 2024/10/02 10:08:40 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(char *msg, t_fixed *f, t_dynamic *d, int fd[][2])
{
	perror(msg);
	free_info(f, d);
	close_all(fd, f);
	if (d->c_cmd == f->cmd_l && ft_strcmp(msg, "path") == 0)
		exit(127);
	exit(1);
}

void	doc_error(char *msg, t_here_doc *h, int fd[2])
{
	(void)fd;
	perror(msg);
	free_here(h);
	if (fd[0] != '\0')
		close(fd[0]);
	if (fd[1] != '\0')
		close(fd[1]);
	exit(1);
}
