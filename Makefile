# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 13:54:33 by kcatrix           #+#    #+#              #
#    Updated: 2022/02/06 13:14:18 by kevyn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

MY_CPPFLAGS = -I$(LIBPATH) -I$(MLXTDIR)

CPPFLAGS = $(MY_CPPFLAGS)

OBJ = $(SRC:.c=.o)

SRC = ./srcs/main.c 

MLXDIR = $(LIBPATH)/mlx
APMLX = $(MLXDIR)/mlx.a

LDLIBS = $(APMLX) -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) 
	@$(MAKE) -j -s --no-print-directory -C mlx/
	$(CC) $(LDLIBS) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@$(MAKE) -s --no-print-directory -C mlx/ clean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: pipex all clean fclean re
