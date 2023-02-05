NAME = cube

SRCS = main.c
AMLX = mlx/libmlx.a
ALIBFT = Others/libft/libft.a

OBJS = $(SRCS:.c=.o)

LFLAGS = -Lmlx -lXext -lX11
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(AMLX) $(ALIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

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
	make fclean -C mlx
	make fclean -C Others/libft

re: fclean all

.PHONY: re clean fclean all
