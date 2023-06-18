# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 15:13:33 by rphuyal           #+#    #+#              #
#    Updated: 2023/01/20 19:02:54 by rphuyal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
RESET = $(shell tput sgr0)

LIBFT_DIR = libft
LIBFT_INCLUDE = -I$(LIBFT_DIR)
LINK_PATH = -L $(LIBFT_DIR) -lft

SRC = src/main/main.c \
		src/main/validate_inputs.c \
		src/stack/swap.c \
		src/stack/push.c \
		src/stack/rotate.c \
		src/stack/reverse_rotate.c \
		src/algorithm/the_sorting_portal.c \
		utils/print_stack.c \
		utils/find_index.c \
		utils/stack_utils.c \

OBJ = $(SRC:.c=.o)

all:	$(NAME)

libft:
		@make -sC $(LIBFT_DIR)
		@echo "$(GREEN)Built libft!$(RESET)"
	
$(NAME):    $(libft)
		@@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT_INCLUDE) $(LINK_PATH)
		@echo "$(GREEN)Compilation successful!$(RESET)"
		
clean:
		@make -sC $(LIBFT_DIR) clean
		@$(RM) $(OBJ)
		@echo "$(GREEN)Cleaned objects!$(RESET)"

fclean:    clean
		@$(RM) $(NAME)
		@echo "$(GREEN)Cleaned executable!$(RESET)"

re:	fclean $(NAME)