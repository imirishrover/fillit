NAME = fillit
FILES = fill.c init.c print.c read.c validate.c main.c
OBJ = $(patsubst %.c, %.o, $(FILES))
LIB = -L. -lft

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -I main.h read.h -I./libft/includes -c $(FILES)
	gcc -Wall -Wextra -Werror $(OBJ) $(LIB) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)