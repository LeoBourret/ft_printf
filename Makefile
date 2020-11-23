NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PATH_SRC = ./src/
PATH_INC = ./inc/
SRC = ./src/ft_display.c \
			./src/ft_manage_addr.c \
			./src/ft_manage_char.c \
			./src/ft_manage_char.c \
			./src/ft_manage_flags.c \
			./src/ft_manage_hex.c \
			./src/ft_manage_int.c \
			./src/ft_manage_uint.c \
			./src/ft_manage_percent.c \
			./src/ft_manage_str.c \
			./src/ft_manage_type.c \
			./src/ft_manage_width.c \
			./src/ft_manager.c \
			./src/ft_printf.c \
			./src/ft_tools.c \
			./src/ft_tools2.c

OBJ = ./src/ft_display.o \
			./src/ft_manage_addr.o \
			./src/ft_manage_char.o \
			./src/ft_manage_char.o \
			./src/ft_manage_flags.o \
			./src/ft_manage_hex.o \
			./src/ft_manage_int.o \
			./src/ft_manage_uint.o \
			./src/ft_manage_percent.o \
			./src/ft_manage_str.o \
			./src/ft_manage_type.o \
			./src/ft_manage_width.o \
			./src/ft_manager.o \
			./src/ft_printf.o \
			./src/ft_tools.o \
			./src/ft_tools2.o

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(PATH_INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(MAKE) bonus -C ./libft/
	mv ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)
	$(MAKE) clean -C ./libft/
fclean : clean
	rm -f $(NAME)
	rm -f ./libft/libft.a
re : fclean all
