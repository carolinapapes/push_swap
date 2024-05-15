# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capapes <capapes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 14:40:46 by capapes           #+#    #+#              #
#    Updated: 2024/05/15 20:47:27 by capapes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = ft_arr.c ft_aux.c ft_isint.c ft_moves.c ft_moves_2.c ft_stacks.c  ft_sort_fixed.c ft_sort_radix.c push_swap.c
OBJ = $(SRC:.c=.o)
DPS = $(SRC:.c=.d)
LIBFT_PATH	=	./libft
PREQ = Makefile $(LIBFT_PATH)/libft.a
NAME = push_swap

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

%.o: %.c
	@$(CC) $(CFLAGS) -c  -MMD -o $@ $<
	@echo "$(GRAY)⏳compiling		$<$(DEF_COLOR)"

%.d: %.c
	@$(CC) $(CFLAGS) -M -MP -MT '$(<:.c=.o)' -MF $@ $<

clean:
	@rm -f $(OBJ) $(DPS)
	@Make -C $(LIBFT_PATH) clean
	@echo "$(RED)🧹clean		pushswap$(DEF_COLOR)"

fclean:
	@rm -f $(NAME) $(OBJ) $(DPS)
	@Make -C $(LIBFT_PATH) fclean
	@echo "$(RED)🧹clean		pushswap$(DEF_COLOR)"

re: fclean all 

.PHONY: all clean fclean re