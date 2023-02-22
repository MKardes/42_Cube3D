NAME = cube
NAME_MAC = cube

SRCS = SRCS/*.c
AMLX = Others/mlx/libmlx.a
ALIBFT = Others/libft/libft.a

MFLAGS = -framework OpenGL -framework AppKit -o3
LFLAGS = -IINC -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Wextra
CC = gcc -g

all: $(NAME)

$(NAME): $(AMLX) $(ALIBFT) $(SRCS) INC/cube.h
	$(CC) $(CFLAGS) $(SRCS) $(AMLX) $(ALIBFT) $(LFLAGS) -o $(NAME) 

mac: $(NAME_MAC)

$(NAME_MAC): $(AMLX) $(ALIBFT) $(SRCS) INC/cube.h
	$(CC) $(CFLAGS) $(SRCS) $(AMLX) $(ALIBFT) $(MFLAGS) -o $(NAME_MAC)

$(AMLX):
	make -C Others/mlx

$(ALIBFT):
	make -C Others/libft

clean:
	rm -rf $(OBJS)
	make clean -C Others/mlx
	make clean -C Others/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C Others/libft

re: fclean all

.PHONY: re clean fclean all
