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

SRC_NAME = main.c fill.c init.c print.c read.c validate.c deinit.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = read.h main.h

.PHONY: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@$(CC) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)
	@echo "FILLIT READY"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -I$(LIB_DIR) -o $@ -c $<
	@echo "OBJECT FILES HAS BEEN CREATED"

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "CLEAN OK"
fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)
	@echo "FCLEAN OK"
re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

relib:
	@$(MAKE) -C $(LIB_DIR) re --no-print-directory
	@$(MAKE) re --no-print-directory