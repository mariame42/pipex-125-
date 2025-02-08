/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:59:54 by meid              #+#    #+#             */
/*   Updated: 2024/09/30 11:53:54 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct line1
{
	int			len;
}				t_info;

typedef struct list
{
	struct list	*next;
	char		*con;
	int			len;
}				t_list;

char			*get_next_line(t_info *i);
int				ftt_strlen(char *str);
char			*ftt_strchr_allocation(char *line, int len);
char			*ftt_strchar_rev(char *line, int c);
char			*ftt_strjoin(char *line, char *buffer);
char			*ftt_strchr(char *line, int c);
char			*ready_for_next(char *line);
char			*read_line(char *line, int fd);
char			*clean_line(char *line);
char			*ready_for_next(char *line);
t_list			*ftt_lstnew(void *con);
int				ftt_lstsize(t_list *lst);
void			ftt_lstadd_back(t_list **lst, t_list *new);
t_list			*ftt_lstlast(t_list *lst);
int				ftt_strcmp(char *s1, char *s2);
char			*ftt_strdup(char *s1);
int				ftt_con_size(t_list *lst);
char			*ftt_strcat(char *dest, const char *src);
void			get_file(char *limit);
t_list			*get_list(char *limit);
void			ftt_lstclear(t_list **lst);
void			ftt_lstdelone(t_list *lst);
char			*ftt_strcpy(char *s1, char *s2);
void			while_loop(t_info *i, char *cur, t_list *all, char *lim);

#endif