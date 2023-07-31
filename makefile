# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theodelgrange <theodelgrange@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 12:51:16 by tdelgran          #+#    #+#              #
#    Updated: 2023/07/31 12:00:32 by theodelgran      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC= gcc

CFLAGS= -Wall -Wextra -Werror  #-fsanitize=address

RM= rm -f

SRC =	src/add.c \
		src/main.c \
		src/parsing.c \
		src/push_swap.c \
		src/radix.c \
		src/sort.c \
		src/sort_4.c \
		src/sort_5.c \
		src/utils.c \
		src/utils2.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
			
re: fclean all

.PHONY: clean fclean all re