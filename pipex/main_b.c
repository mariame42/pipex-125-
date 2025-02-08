/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:20:47 by meid              #+#    #+#             */
/*   Updated: 2024/10/02 10:09:09 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_fixed		f;
	t_dynamic	d;
	t_here_doc	h;
	int			re;

	if (ac < 5)
		exit(1);
	if (ft_strcmp(av[1], "here_doc") == 0 && ac == 6)
	{
		h = here_doc_info(av);
		get_file(h.limiter);
		re = the_doc_family(&h, env);
		unlink("here_doc");
		return (re);
	}
	f = send_t_fixed_info(ac, av);
	d = send_dinamic_info(ac);
	re = make_big_family(&f, &d, env);
	return (re);
}
