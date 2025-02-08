/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:00:59 by meid              #+#    #+#             */
/*   Updated: 2024/10/01 22:54:53 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_here_doc	here_doc_info(char **av)
{
	t_here_doc	h;
	char		**s_cmd;
	char		**s_cmd1;

	s_cmd = ft_split(av[3], ' ');
	s_cmd1 = ft_split(av[4], ' ');
	h.limiter = av[2];
	h.file = av[5];
	h.cmd = s_cmd[0];
	h.cmd_f = s_cmd;
	h.cmd1 = s_cmd1[0];
	h.cmd1_f = s_cmd1;
	return (h);
}

void	free_here(t_here_doc *h)
{
	free_array(h->cmd_f);
	free_array(h->cmd1_f);
}

t_fixed	send_t_fixed_info(int ac, char **av)
{
	t_fixed	f;
	int		i;

	i = 0;
	f.count = ac - 3;
	f.cmd = get_arr_cmd(av, f.count);
	f.file1 = av[1];
	f.file2 = av[ac - 1];
	f.pipe = f.count - 1;
	f.cmd_1 = 0;
	f.cmd_l = f.count - 1;
	while (i < f.count)
	{
		if (ft_strcmp("awk", f.cmd[i]) == 0)
		{
			f.cmd_f = awk_arr_cmd_f(av, f.count, &f);
			return (f);
		}
		i++;
	}
	f.cmd_f = get_arr_cmd_f(av, f.count);
	return (f);
}

t_dynamic	send_dinamic_info(int ac)
{
	t_dynamic	d;

	d.c_cmd = 0;
	d.c_pipe = 0;
	d.pids = ft_calloc((ac - 3), sizeof(pid_t));
	if (!d.pids)
		exit(1);
	d.f_fd = malloc(sizeof(int) * 2);
	if (!d.f_fd)
		exit(1);
	d.f_fd[0] = 0;
	d.f_fd[1] = 0;
	return (d);
}

void	free_info(t_fixed *arg, t_dynamic *d_arg)
{
	free_array(arg->cmd);
	free(d_arg->pids);
	d_arg->pids = NULL;
	free(d_arg->f_fd);
	d_arg->f_fd = NULL;
	free_array_ar(arg->cmd_f);
}
