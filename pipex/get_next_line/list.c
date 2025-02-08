/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:07:18 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 12:09:25 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ftt_lstnew(void *con)
{
	t_list	*new;

	new = malloc((sizeof(t_list)));
	if (new)
	{
		new->con = con;
		new->len = ftt_strlen(con);
		new->next = NULL;
	}
	return (new);
}

void	ftt_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ftt_lstlast(*lst);
	last->next = new;
}

t_list	*ftt_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ftt_con_size(t_list *lst)
{
	int		con_s;
	t_list	*tmp;

	con_s = 0;
	tmp = lst;
	while (tmp)
	{
		con_s += tmp->len;
		tmp = tmp->next;
	}
	return (con_s);
}

void	ftt_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	if (!lst)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->con);
		free(tmp);
	}
	*lst = NULL;
}
