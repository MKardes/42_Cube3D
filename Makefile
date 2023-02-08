NAME = cube

SRCS = main.c
AMLX = mlx/libmlx.a
ALIBFT = Others/libft/libft.a

LFLAGS = -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(AMLX) $(ALIBFT) $(SRCS) cube.h
	$(CC) $(CFLAGS) $(SRCS) $(AMLX) $(ALIBFT) $(LFLAGS) -o $(NAME) 

$(AMLX):
	make -C mlx

$(ALIBFT):
	make -C Others/libft

clean:
	rm -rf $(OBJS)
	make clean -C mlx
	make clean -C Others/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C Others/libft

re: fclean all

.PHONY: re clean fclean all
