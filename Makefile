# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 02:37:00 by stune             #+#    #+#              #
#    Updated: 2021/06/22 20:39:37 by nmisfit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	main.c\
		main_utils.c\
		_execve.c\
		_execve_utils.c\
		builtins/builtins.c\
		builtins/envp_utils.c\
		builtins/_export.c\
		builtins/_export_utils.c\
		builtins/_echo.c\
		builtins/_unset.c\
		builtins/_exit.c\
		builtins/_cd.c\
		free_all_and_exit.c\
		utils.c\
		command_loop.c\
		envp_construct.c\
		error_hand.c\
		termcaps.c\
		termcaps_utils.c\
		double_list.c\
		_pipe.c\
		_redirect.c\
		cmd_utils.c\
		
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAG = -Wall -Wextra -Werror
LIB = libft.a
LIB_PATH = libft/
LIB_TERMCAP = -ltermcap
INCLUDES = -I./includes -I./libft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) bonus -C $(LIB_PATH)
	@$(CC) $(CFLAG) -L$(LIB_PATH) $(INCLUDES) -lft -ltermcap $(OBJ) -o $(NAME)

%.o: %.c 
	@$(CC) $(INCLUDES) -c $(CFLAG) -o $@ $<

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIB_PATH)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIB_PATH)

re: fclean all

commit:
	git add .
	git commit -m 'change'
	git push
	
gstat:
	git status

run: re
	$(MAKE) clean
	./$(NAME)

debug: $(NAME)
	./$(NAME)
