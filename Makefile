NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Werror -Wextra
PATH_SRC = ./srcs/
PATH_INC = ./inc/
SRC = ./srcs/ft_display.c \
			./srcs/ft_manage_addr.c \
			./srcs/ft_manage_char.c \
			./srcs/ft_manage_char.c \
			./srcs/ft_manage_flags.c \
			./srcs/ft_manage_hex.c \
			./srcs/ft_manage_int.c \
			./srcs/ft_manage_uint.c \
			./srcs/ft_manage_percent.c \
			./srcs/ft_manage_str.c \
			./srcs/ft_manage_type.c \
			./srcs/ft_manage_width.c \
			./srcs/ft_manager.c \
			./srcs/ft_printf.c \
			./srcs/ft_tools.c \
			./srcs/ft_tools2.c

OBJ = ./srcs/ft_display.o \
			./srcs/ft_manage_addr.o \
			./srcs/ft_manage_char.o \
			./srcs/ft_manage_char.o \
			./srcs/ft_manage_flags.o \
			./srcs/ft_manage_hex.o \
			./srcs/ft_manage_int.o \
			./srcs/ft_manage_uint.o \
			./srcs/ft_manage_percent.o \
			./srcs/ft_manage_str.o \
			./srcs/ft_manage_type.o \
			./srcs/ft_manage_width.o \
			./srcs/ft_manager.o \
			./srcs/ft_printf.o \
			./srcs/ft_tools.o \
			./srcs/ft_tools2.o

RED				:= $(shell tput -Txterm setaf 1)
GREEN			:= $(shell tput -Txterm setaf 2)
YELLOW			:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE		:= $(shell tput -Txterm setaf 4)
PURPLE			:= $(shell tput -Txterm setaf 5)
BLUE			:= $(shell tput -Txterm setaf 6)
WHITE			:= $(shell tput -Txterm setaf 7)

all : $(NAME)

message:
	@echo ""
	@echo "$(LIGHTPURPLE)		[	compiling ft_printf	]"
	@echo ""

%.o : %.c
	$(CC) $(CFLAGS) -I$(PATH_INC) -o $@ -c $<

$(NAME): message $(OBJ)
	@echo ""
	@echo "$(GREEN)		[	generating libftprintf		]"
	ar -rcs $(NAME) $(OBJ)

clean :
	@echo ""
	@echo "$(PURPLE)		[	cleaning ft_printf	]"
	@echo ""
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
	rm -f ./libft/libft.a
re : fclean all
