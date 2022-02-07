# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 13:54:33 by kcatrix           #+#    #+#              #
#    Updated: 2022/02/07 12:33:27 by kcatrix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra

NAME = so_long

MY_CPPFLAGS = -I$(LIBPATH) -I$(MLXTDIR)

CPPFLAGS = $(MY_CPPFLAGS)

OBJ = $(SRC:.c=.o)

SRC = ./srcs/main.c 

MLXDIR = $(LIBPATH)/mlx
APMLX = $(MLXDIR)/mlx.a

LDLIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) 
	$(CC) $(CFLAGS) $(LDLIBS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: pipex all clean fclean re
