NAME	= fillit

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRC_DIR = ./srcs/
INC_DIR	= ./includes/
OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_DIR))

SRC_NAME = main.c fill.c init.c read.c validate.c deinit.c ft_bzero.c ft_lstadd.c ft_lstnew.c ft_memalloc.c ft_memdel.c ft_memset.c ft_putchar.c ft_putendl.c ft_putstr.c ft_strdel.c ft_strlen.c ft_strnew.c ft_putstr_fd.c ft_putchar_fd.c ft_memcpy.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = main.h

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
