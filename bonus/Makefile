NAME = marathon-03

SRC = ft_base_lib.c ft_check_lib.c ft_make_lib.c ft_solve_lib.c main.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: clean all
