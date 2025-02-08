/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:21:03 by meid              #+#    #+#             */
/*   Updated: 2024/10/02 10:08:48 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line/get_next_line.h"
# include <fcntl.h> //open flags
# include <stdint.h>
# include <stdio.h>     // perror
# include <stdlib.h>    // exit, malloc, free
# include <string.h>    // strerror
# include <sys/types.h> //waitpid flags
# include <sys/wait.h>  //wait, waitpid
# include <unistd.h>    // open, close, read, write, access, dup, dup2, execve,
# include <limits.h>

# ifndef MAX_FD
#  define MAX_FD FOPEN_MAX
# endif

typedef struct arg_f_info
{
	char	*file1;
	char	*file2;
	int		count;
	char	**cmd;
	char	***cmd_f;
	int		pipe;
	int		cmd_1;
	int		cmd_l;
	int		part_num_awk;
}			t_fixed;

typedef struct arg_d_info
{
	int		c_cmd;
	int		c_pipe;
	int		*pids;
	int		*f_fd;
}			t_dynamic;

/*----------print.c------------*/

void		handle_error(char *msg, t_fixed *f, t_dynamic *d, int fd[][2]);

/*---------------path.c----------------*/

char		*get_path(char *cmd, char **env);

/*--------------info.c------------------*/
t_dynamic	send_dinamic_info(int ac);
t_fixed		send_t_fixed_info(int ac, char **av);
char		**get_arr_cmd(char **av, int cmd_count);
char		***get_arr_cmd_f(char **av, int cmd_count);
char		***awk_arr_cmd_f(char **av, int cmd_count, t_fixed *f);

int			free_array_ar(char ***array);
void		free_info(t_fixed *arg, t_dynamic *d_arg);

/*---------------libft-----------------*/
char		**ft_split(char *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			free_array(char **array);
char		*first_word(char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_strcmp(char *s1, char *s2);

/*utils3*/

int			ft_part_num(char *str);
int			*ft_partlen(char **str, int parts);
int			loop_len(char **str);
/*awk*/
char		**get_array(char **arr, char **s, int *parts_len);
char		**split_awk(char *s, t_fixed *f);

/*----------------big_family.c----------------*/
int			make_big_family(t_fixed *f, t_dynamic *d, char **env);
void		execute_children(t_fixed *f, t_dynamic *d, char **env, int fd[][2]);
int			file1(t_fixed *f, t_dynamic *d, int fd[][2]);
int			file2(t_fixed *f, t_dynamic *d, int fd[][2]);
void		family_loops(int fd[][2], t_fixed *f, t_dynamic *d, char **env);

/*---------------close_pip.c-----------------*/
int			close_used_pipes(int fd[][2], t_fixed *f, t_dynamic *d);
int			close_unused_pipes(int fd[][2], t_fixed *f, t_dynamic *d);
int			close_all(int fd[][2], t_fixed *f);

/*====NEW=====NEW====NEW====NEW====NEW====NEW====NEW====NEW====NEW===*/

/*------------------------------here_doc--------------------------------*/

typedef struct HereDoc
{
	char	*limiter;
	char	**cmd_f;
	char	**cmd1_f;
	char	*file;
	char	*tmp;
	char	*cmd;
	char	*cmd1;
}			t_here_doc;

/*--------------info.c------------------*/
t_here_doc	here_doc_info(char **av);
void		free_here(t_here_doc *h);

/*--------------here_doc.c------------------*/

int			the_doc_family(t_here_doc *h, char **env);
void		child1(char **env, int fd_write, t_here_doc *h, int fd[2]);
void		child2(char **env, int fd_read, t_here_doc *h, int fd[2]);

/*--------------print.c------------------*/
void		doc_error(char *msg, t_here_doc *h, int fd[2]);

#endif