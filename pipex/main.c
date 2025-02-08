/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:15:17 by meid              #+#    #+#             */
/*   Updated: 2024/10/01 22:48:57 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_fixed		f;
	t_dynamic	d;
	int			re;

	if (ac != 5)
		exit(1);
	f = send_t_fixed_info(ac, av);
	d = send_dinamic_info(ac);
	re = make_big_family(&f, &d, env);
	return (re);
}
