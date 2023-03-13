NAME = cub3D

UNAME		:= $(shell uname -s)

SRCS = SRCS/*.c
ALIBFT = Others/libft/libft.a
LINE = Others/get_next_line/get_next_line.a

CFLAGS = -Wall -Wextra
CC = gcc -g

ifeq ($(UNAME), Linux)
	MFLAGS = -IINC -lXext -lX11 -lm
	MLX = Others/mlx_linux
	AMLX = Others/mlx_linux/libmlx.a
else ifeq ($(UNAME), Darwin)
	MFLAGS = -framework OpenGL -framework AppKit -o3
	MLX = Others/mlx
	AMLX = Others/mlx/libmlx.a
endif

all: $(NAME)

$(NAME): $(AMLX) $(ALIBFT) $(LINE) $(SRCS) INC/cube.h
	$(CC) $(CFLAGS) $(SRCS) $(AMLX) $(ALIBFT) $(LINE) $(MFLAGS) -o $(NAME) 

$(AMLX):
	make -C $(MLX)

$(ALIBFT):
	make -C Others/libft

$(LINE):
	make -C Others/get_next_line

clean:
	rm -rf $(OBJS)
	make clean -C $(MLX)
	make clean -C Others/get_next_line
	make clean -C Others/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C Others/get_next_line
	make fclean -C Others/libft

re: fclean all

.PHONY: re clean fclean all
