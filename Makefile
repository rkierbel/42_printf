# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 17:32:09 by rkierbel          #+#    #+#              #
#    Updated: 2021/04/29 14:46:32 by rkierbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c options_mgmt.c print_chars.c print_ints.c \
	  print_ptrs.c print_hex_and_u.c utils.c utils_a.c utils_b.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(HEADER)
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
