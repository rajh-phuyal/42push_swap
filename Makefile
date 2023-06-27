# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 15:13:33 by rphuyal           #+#    #+#              #
#    Updated: 2023/06/26 16:18:52 by rphuyal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = push_swap

CC    = @gcc

FLAGS = -g -fsanitize=address

LFT   = libft/libft.a

INC   = -I./libft

SRC = src/core/main.c \
		src/core/validate_inputs.c \
		src/stack/swap.c \
		src/stack/push.c \
		src/stack/rotate.c \
		src/stack/reverse_rotate.c \
		src/algorithm/the_sorting_portal.c \
		src/algorithm/stage_one.c \
		src/algorithm/stage_two.c \
		src/algorithm/helpers/min_max.c \
		src/algorithm/helpers/finders.c \
		src/algorithm/helpers/only_three.c \
		src/algorithm/helpers/map_and_sort.c \
		src/algorithm/helpers/sending_cost.c \
		src/global_helpers/print_stack.c \
		src/global_helpers/find_index.c \
		src/global_helpers/stack_utils.c \

OBJ   = $(patsubst src/%.c, obj/%.o, $(SRC))

# COLORS
CBOLD   = \033[0;1m
RED     = \033[0;41m
GREEN   = \033[0;42m
BLUE   = \033[0;44m
YELLOW  = \033[0;43m
RESET   = \033[0m

all: $(LFT) obj $(NAME)

$(NAME): $(OBJ)
	@echo "$(CBOLD)$(YELLOW)  Compiling $(NAME) $(RESET)"
	$(CC) $(FLAGS) -o $@ $^ $(LFT)
	@echo "$(CBOLD)$(GREEN)    $(NAME) ready!  $(RESET)"

$(LFT):
	@echo "$(CBOLD)$(YELLOW)    Compiling Libft   $(RESET)"
	@make -sC ./libft
	@echo "$(CBOLD)$(GREEN)      Libft ready!    $(RESET)\n ↪"

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@make -sC libft clean > /dev/null
	@rm -rf $(OBJ) obj
	@echo "$(CBOLD)$(BLUE)    Objects removed!  $(RESET)"

fclean: clean
	@make -sC libft fclean
	@rm -rf $(NAME)
	@echo "$(CBOLD)$(BLUE)    Binaries removed! $(RESET)"

re: fclean all

.PHONY: all