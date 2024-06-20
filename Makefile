
NAME = libso_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = main.c gnl.c floodfill.c	mlxinit.c key_hooks.c checks.c
SRC_DIR = srcs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = objs
PROGRAM = so_long

all: $(PROGRAM)

$(PROGRAM):$(NAME)
	$(CC) $(CFLAGS)  -g $(NAME) -o $(PROGRAM)  -Linclude/minilibx-linux -lmlx -lXext -lX11 -lm

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c -g $<

clean: all
	rm -rf objs

fclean: clean
	rm -rf $(NAME) $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re
