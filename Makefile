NAME	= fillit

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRC_DIR = ./srcs/
INC_DIR	= ./includes/
OBJ_DIR = ./obj/
LIB_DIR	= ./libft/

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_DIR))

SRC_NAME = main.c fill.c init.c read.c validate.c deinit.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = read.h main.h

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LIB_DIR)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LIB_DIR) -lft
	@echo "$(OKC)FILLIT:\t\tFillit ready$(NOC)"
	@echo "======"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo -n =

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)FILLIT:\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)
	@echo "$(WAC)FILLIT:\t\tRemoving fillit executable$(NOC)"

re: fclean all