# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 02:26:15 by ccastill          #+#    #+#              #
#    Updated: 2021/05/15 02:23:47 by ccastill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = ./src/push_swap.h ./lib/libft/libft.h

FLAGS = gcc -I -Wall -Wextra -Werror -g

FUN = ./src/main.c ./src/check_argv.c ./src/prnt_error_exit.c ./src/ft_atoi_range.c ./src/operations/swap.c \
		./src/operations/rotate.c ./src/operations/rotate_reverse.c  ./src/operations/push.c
	
OBJ = $(FUN:.c=.o)

LIBFT = ./lib/libft/libft.a

all: $(NAME)

$(LIBFT): 
	@$(MAKE) -C ./lib/libft/

$(NAME): $(OBJ) $(LIBFT) $(INCLUDES)
	@$(FLAGS) $(FUN) $(LIBFT) -Llib/libft -lft -o $(NAME)

clean:
	@rm -f $(OBJ) *.o ./lib/libft/*.o ./lib/get_next_line/*.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: clean fclean all

norma:
	@echo "\e[42m------ NOrminette version ------\e[0m"
	norminette -v
	@echo
	@echo "\e[42m------ main path ------\e[0m"
	norminette ./src
	@echo
	@echo "\e[42m------ get_next_line ------\e[0m"
	norminette lib/get_next_line
	@echo
	@echo "\e[42m------ libft folder ------\e[0m"
	norminette lib/libft
