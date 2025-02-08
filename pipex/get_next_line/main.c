/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:46:43 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 17:25:15 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_list(char *limit)
{
	char	*lim;
	char	*cur;
	t_list	*all;
	t_info	i;

	i = (t_info){0};
	(void)limit;
	lim = malloc(sizeof(char) * ftt_strlen(limit) + 2);
	if (!lim)
		return (NULL);
	ftt_strcpy(lim, limit);
	ftt_strcat(lim, "\n");
	cur = get_next_line(&i);
	if (ftt_strcmp(cur, lim) == 0)
	{
		free(lim);
		free(cur);
		return (NULL);
	}
	all = ftt_lstnew(ftt_strdup(cur));
	free(cur);
	while_loop(&i, cur, all, lim);
	return (all);
}

void	while_loop(t_info *i, char *cur, t_list *all, char *lim)
{
	t_list	*c;

	while (1)
	{
		cur = get_next_line(i);
		c = ftt_lstnew(ftt_strdup(cur));
		if (!cur)
			break ;
		if (ftt_strcmp(cur, lim) == 0)
		{
			free(lim);
			ftt_lstdelone(c);
			free(cur);
			break ;
		}
		ftt_lstadd_back(&all, c);
		free(cur);
	}
}

void	get_file(char *limit)
{
	t_list	*lst;
	char	*array;
	int		size;
	t_list	*tmp;
	int		fd;

	lst = get_list(limit);
	array = malloc(sizeof(char) * ftt_con_size(lst) + 1);
	size = sizeof(char) * ftt_con_size(lst);
	if (!array)
		return ;
	array[0] = '\0';
	tmp = lst;
	while (tmp)
	{
		ftt_strcat(array, (char *)tmp->con);
		tmp = tmp->next;
	}
	ftt_lstclear(&lst);
	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	write(fd, array, size);
	free(array);
	close(fd);
}
