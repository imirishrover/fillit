NAME	= fillit

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRC_DIR = ./srcs/
INC_DIR	= ./includes/
OBJ_DIR = ./obj/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_DIR))

SRC_NAME = main.c fill.c init.c read.c validate.c deinit.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = read.h main.h

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	make -C $(LFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C $(LFT_PATH) fclean
	rm -f $(NAME)

re: fclean all