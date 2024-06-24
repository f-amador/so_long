
NAME = libso_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = main.c gnl.c floodfill.c	mlxinit.c key_hooks.c checks.c putexit.c
SRC_DIR = srcs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = objs
PROGRAM = so_long
MLX_DIR = include/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a


all: $(MLX_LIB) $(PROGRAM)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(PROGRAM):$(NAME)
	$(CC) $(CFLAGS)  -g $(NAME) -o $(PROGRAM)  -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c -g $<
	

clean:
	rm -rf objs
	make clean -C ./$(MLX_DIR)

fclean: clean
	rm -rf $(NAME) $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re
