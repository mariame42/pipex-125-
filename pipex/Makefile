# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meid <meid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 20:21:09 by meid              #+#    #+#              #
#    Updated: 2024/10/01 22:19:22 by meid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = info.c path.c libft/awk_split.c libft/split.c libft/utils1.c libft/utils2.c libft/utils3.c close_pip.c big_family.c print.c here_doc_f.c \
	get_next_line/get_next_line_utils.c get_next_line/get_next_line_utils2.c get_next_line/get_next_line.c get_next_line/list.c \
	get_next_line/main.c get_info.c

MSRC = main.c
 
OBJ = $(SRC:.c=.o)

MOBJ = $(MSRC:.c=.o)

BONUS = main_b.c

B_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MOBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MOBJ) -o $(NAME)

bonus :	$(OBJ) $(B_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(B_OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(MOBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
