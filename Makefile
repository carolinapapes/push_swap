# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: capapes <capapes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 14:40:46 by capapes           #+#    #+#              #
#    Updated: 2024/05/09 15:07:45 by capapes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c ft_parser.c ft_isint.c ft_idx.c ft_moves.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH	=	./libft
PREQ = printf.h Makefile $(LIBFT_PATH)/libft.a
NAME = push_swap

# Metodo implicito
# Target
all: make_libs ${NAME}

make_libs:
	make -C $(LIBFT_PATH)
	make -C $(LIBFT_PATH) bonus

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft
	@echo "Compiled $@"

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $< 
	@echo "Compiled $@\n"

clean:
	@rm -f $(OBJ)
	Make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@Make -C $(LIBFT_PATH) fclean

re: fclean all 

.PHONY: all clean fclean re