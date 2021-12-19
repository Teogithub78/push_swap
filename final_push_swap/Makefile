NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PATH_SRC = ./src/
PATH_INC = ./inc/
SRC = ./src/list_init.c \
						./src/parser_propre.c \
						./src/ft_manage_int.c \
						./src/ft_manage_octal.c \
						./src/ft_manage_schar.c \

OBJ = $(SRC:.c=.o)

FSANITIZE = -fsanitize=address

G3 = -g3

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
		$(NAME) $(OBJ)

fs : $(OBJ)
	$(CC) $(CFLAGS) $(FSANITIZE) -I$(PATH_INC) -c $< -o $@

# gcc push_swap.c check_arg.c manage_arg.c list_init.c utils.c utils_algo.c operations.c algo_small.c annid_algo.c


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
