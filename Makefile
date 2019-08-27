# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleduc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 16:40:19 by aleduc            #+#    #+#              #
#    Updated: 2018/07/21 17:43:47 by aleduc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_PATH = ./
OBJ_PATH = obj/
SRC_NAME = btree_apply_infix.c btree_create_node.c btree_insert_data.c \
		   display_data.c ft_error.c ft_ls.c ft_opts.c main.c no_options.c \
		   ft_args.c ft_ls_btree.c ft_path.c ft_ret.c ft_path2.c opt_l.c \
		   norm_one.c norm_two.c norm_three.c norm_four.c norm_five.c \
		   norm_six.c norm_seven.c norm_eight.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	@printf "\r\033[K""\r\033[K""\033[32mCompilation...\033[0m"
	@$(CC) $(CFLAGS) -L libft -l ft -o $(NAME) $(OBJ)
	@printf "\r\033[K""\r\033[K""\033[32mCompilation terminee !\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c libft/libft.h ft_ls.h
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\033[42m \033[0m"

.PHONY: all, clean, fclean, re

clean :
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[1;30mFichier .o supprime.\033[0m"

fclean : clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[1;30mExecutable detruit.\033[0m"

re : fclean all

norme :
	@norminette $(SRC_PATH) $(OBJ_PATH)
