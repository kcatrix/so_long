CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror $(BUFFER)

MY_CPPFLAGS = -I$(LIBPATH) -I$(LIBFTDIR) -I$(GNLDIR)

CPPFLAGS = $(MY_CPPFLAGS)

NAME = so_long

SRCDIR = ./srcs

SRC = $(wildcard $(SRCDIR)/*.c)

LIBPATH = ./lib

GNLDIR = $(LIBPATH)/GNL
APGNL = $(GNLDIR)/get_next_line.a

LIBFTDIR = $(LIBPATH)/libft
APLIBFT = $(LIBFTDIR)/libft.a

OBJ = $(SRC:.c=.o)

LDLIBS = $(APGNL) $(APLIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit 

BUFFER = -D BUFFER_SIZE=1

all:
	@$(MAKE) -j $(NAME)	

$(NAME): $(SRC)
	@$(MAKE) -j -s --no-print-directory -C lib/libft/
	@$(MAKE) -j -s --no-print-directory -C lib/gnl/
	$(CC) $(LDLIBS) $(CFLAGS) $(SRC) $(APLIBFT) $(APGNL) -o $(NAME)

%.o : %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $(SRC) $< -o $@ 

clean:
	@$(MAKE) -s --no-print-directory -C lib/libft/ clean
	@$(MAKE) -s --no-print-directory -C lib/gnl/ clean 
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -s --no-print-directory -C lib/libft/ fclean
	@$(MAKE) -s --no-print-directory -C lib/gnl/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
