NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PATH_SRC = ./src/
PATH_INC = ./inc/
SRC = ./src/ft_manage_addr.c \
						./src/ft_manage_hexa.c \
						./src/ft_manage_int.c \
						./src/ft_manage_octal.c \
						./src/ft_manage_schar.c \
						./src/ft_manage_str.c \
						./src/ft_manage_type.c \
						./src/ft_manage_uint.c \
						./src/ft_printf.c

OBJ = ./src/ft_manage_addr.o \
						./src/ft_manage_hexa.o \
						./src/ft_manage_int.o \
						./src/ft_manage_octal.o \
						./src/ft_manage_schar.o \
						./src/ft_manage_str.o \
						./src/ft_manage_type.o \
						./src/ft_manage_uint.o \
						./src/ft_printf.o

all : $(NAME)

message:
		@echo ""
		@echo "		[	compiling push_swap		]"
		@echo ""

%.o : %.c
		$(CC) $(CFLAGS) -I$(PATH_INC) -c $< -o $@

$(NAME): message $(OBJ)
		@echo ""
		@echo "		[	COMPILING libft	]"
		@echo ""
		$(MAKE) -C ./libft/
		mv ./libft/libft.a $(NAME)
		@echo "-------------------------"
		@echo "		[	GENERATING libftprintf	]"
		@echo "-------------------------"
		ar -rcs $(NAME) $(OBJ)

clean :
		@echo "-------------------------"
		@echo "		[	CLEANING FT_PRINTF	]"
		@echo "-------------------------"
		rm -f $(OBJ)
		$(MAKE)	clean -C ./libft/
fclean : clean
		rm -f $(NAME)
		rm -f ./libft/libft.a
re : fclean all
