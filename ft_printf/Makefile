# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adores <adores@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:10:10 by adores            #+#    #+#              #
#    Updated: 2025/07/16 15:30:38 by adores           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC := ft_printstr.c ft_hexaputnbr.c ft_printchar.c ft_printf.c \
	ft_printnbr.c ft_unsputnbr.c ft_printp.c

OBJ := $(SRC:.c=.o)

RM := rm -f
AR := ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all