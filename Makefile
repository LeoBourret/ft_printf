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
SRC_libft = ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c \
		./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c \
		./libft/ft_isdigit.c ./libft/ft_isprint.c  ./libft/ft_memccpy.c \
		./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c \
		./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_putchar.c \
		./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr.c \
		./libft/ft_putnbr_fd.c ./libft/ft_putstr.c ./libft/ft_putstr_fd.c \
		./libftft_split.c ./libft/ft_strchr.c ./libft/ft_strcpy.c \
		./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c \
		./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strmapi.c \
		./libft/ft_strncmp.c ./libft/ft_strnstr.c ./libft/ft_strrchr.c \
		./libft/ft_strtrim.c

OBJ_libft = ./libft/ft_atoi.o ./libft/ft_bzero.o ./libft/ft_calloc.o \
		./libft/ft_isalnum.o ./libft/ft_isalpha.o ./libft/ft_isascii.o \
		./libft/ft_isdigit.o ./libft/ft_isprint.o  ./libft/ft_memccpy.o \
		./libft/ft_memchr.o ./libft/ft_memcmp.o ./libft/ft_memcpy.o \
		./libft/ft_memmove.o ./libft/ft_memset.o ./libft/ft_putchar.o \
		./libft/ft_putchar_fd.o ./libft/ft_putendl_fd.o ./libft/ft_putnbr.o \
		./libft/ft_putnbr_fd.o ./libft/ft_putstr.o ./libft/ft_putstr_fd.o \
		./libft/ft_split.o ./libft/ft_strchr.o ./libft/ft_strcpy.o \
		./libft/ft_strdup.o ./libft/ft_strjoin.o ./libft/ft_strlcat.o \
		./libft/ft_strlcpy.o ./libft/ft_strlen.o ./libft/ft_strmapi.o \
		./libft/ft_strncmp.o ./libft/ft_strnstr.o ./libft/ft_strrchr.o \
		./libft/ft_strtrim.o


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
fclean : clean
	rm -f $(NAME)
re : fclean all
