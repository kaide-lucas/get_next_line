NAME = get_next_line.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

src = get_next_line.c get_next_line_utilis.c
OBJ = $(SRC:.c=.o)

all: $(NAME): $(OBJ)
	ar rcs $(NAME) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all