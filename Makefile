# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttshivhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 14:24:20 by ttshivhu          #+#    #+#              #
#    Updated: 2017/11/21 14:26:24 by ttshivhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gameoflife

SRC = main.c get_next_line.c \

FLAG = -g3 -Wall -Werror -Wextra

SILENT = --no-print-directory

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):
	@make -C libft $(SILENT)
	@gcc $(FLAG) -c $(SRC)
	@gcc $(FLAG) $(OBJ)  libft/libft.a -o $(NAME)
	@printf "\x1b[32mCompiled $(NAME) \x1b[0m\n"

clean:
	@make clean -C libft $(SILENT)
	@/bin/rm -f $(OBJ) $(LOBJ) *.o
	@printf "\x1b[31mRemoved object files\x1b[0m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft $(SILENT)
	@printf "\x1b[31mRemoved $(NAME)\x1b[0m\n"

re: fclean all
