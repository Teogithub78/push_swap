NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PATH_SRC = ./src/
PATH_INC = ./inc/
SRC = push_swap.c check_arg.c manage_arg.c list_init.c utils.c utils_algo.c operations.c algo_small.c annid_algo.c

OBJ = $(SRC:.c=.o)

FSANITIZE = -fsanitize=address

G3 = -g3

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -I$(PATH_INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -Iinc $(OBJ) -o $(NAME)

fs : $(OBJ)
	$(CC) $(CFLAGS) $(FSANITIZE) -I$(PATH_INC) -c $< -o $@

# gcc push_swap.c check_arg.c manage_arg.c list_init.c utils.c utils_algo.c operations.c algo_small.c annid_algo.c

clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re
