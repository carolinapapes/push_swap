# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capapes <capapes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 14:40:46 by capapes           #+#    #+#              #
#    Updated: 2024/05/16 12:46:32 by capapes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_arr.c ft_aux.c ft_isint.c ft_moves.c ft_moves_2.c ft_stacks.c  ft_sort_fixed.c ft_sort_radix.c push_swap.c
BUILD_DIR = ./build
OBJ := $(SRC:%.c=$(BUILD_DIR)/%.o)
DPS := $(OBJ:.o=.d)  # Correct dependency file generation
LIBFT_PATH	=	./libft
PREQ = Makefile $(LIBFT_PATH)/libft.a
NAME = push_swap
CPPFLAGS := -MMD -MP

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Metodo implicito
# Target
all: make_libs ${NAME}

make_libs:
	@make -C $(LIBFT_PATH) 
	

$(NAME): ${OBJ} 
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft
	@echo "$(GREEN)📚completed		push_swap.c$(DEF_COLOR)"

$(BUILD_DIR)/%.o: %.c ${DPS} | $(BUILD_DIR)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@echo "$(GRAY)⏳compiling		$<$(DEF_COLOR)"

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@Make -C $(LIBFT_PATH) clean
	@echo "$(RED)🧹clean		pushswap$(DEF_COLOR)"

fclean:
	@rm -rf $(BUILD_DIR)
	@Make -C $(LIBFT_PATH) fclean
	@echo "$(RED)🧹clean		pushswap$(DEF_COLOR)"

re: fclean all 

-include $(DPS)

.PHONY: all clean fclean re
