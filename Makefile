NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./inc/
PATH_SRC = ./src/
PATH_INC = ./inc/

SRC = ./src/ft_display.c \
			./src/ft_manage_addr.c \
			./src/ft_manage_char.c \
			./src/ft_manage_char.c \
			./src/ft_manage_flags.c \
			./src/ft_manage_hex.c \
			./src/ft_manage_int.c \
			./src/ft_manage_percent.c \
			./src/ft_manage_str.c \
			./src/ft_manage_type.c \
			./src/ft_manage_width.c \
			./src/ft_manager.c \
			./src/ft_printf.c \
			./src/ft_tools.c \
			./src/ft_tools2.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
