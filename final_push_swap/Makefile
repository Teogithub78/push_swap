NAME = push_swap
NAME_B = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PATH_SRC = ./srcs/
PATH_INC = ./inc/
PATH_BONUS = ./bonus/
SRC = srcs/push_swap.c srcs/check_arg.c srcs/manage_arg.c srcs/list_init.c srcs/utils.c srcs/utils_algo.c srcs/operations.c srcs/algo_small.c srcs/annid_algo.c \
	srcs/error.c
SRC_B = bonus/get_next_line.c bonus/get_next_line_utils.c bonus/checker.c bonus/error.c bonus/operations.c \
bonus/checker_utils.c bonus/list_init.c manage_arg.c utils_algo.c
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)



FSANITIZE = -fsanitize=address

G3 = -g3

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -I$(PATH_INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I$(PATH_INC) $(OBJ) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(CFLAGS) -I$(PATH_INC) $(OBJ_B) -o $(NAME_B)

clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re
