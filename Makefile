# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 13:54:33 by kcatrix           #+#    #+#              #
#    Updated: 2022/02/04 13:54:42 by kcatrix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

OBJ = $(SRC:.c=.o)

SRC = ./srcs/main.c 

all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: pipex all clean fclean re
