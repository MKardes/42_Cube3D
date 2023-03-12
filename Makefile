NAME = cube
NAME_H = cube
NAME_L = cube

UNAME		:= $(shell uname -s)

SRCS = SRCS/*.c
ALIBFT = Others/libft/libft.a

CFLAGS = -Wall -Wextra
CC = gcc -g

ifeq ($(UNAME), Linux)
	MFLAGS = -IINC -lXext -lX11 -lm
	MLX = Others/mlx_linux
	AMLX = Others/mlx_linux/libmlx.a
	OS = "You are connected from -$(CYAN)$(UNAME)$(X)- 🐧 Welcome"
else ifeq ($(UNAME), Darwin)
	MFLAGS = -framework OpenGL -framework AppKit -o3
	MLX = Others/mlx
	AMLX = Others/mlx/libmlx.a
	OS = "You are connected from 42 school's iMac 🖥 ! Welcome $(CYAN)$(USER)$(X)"
	ifeq ($(USER), yuandre)
		OS = "You are connected from -$(CYAN)MacBook$(X)- 💻 Welcome -$(CYAN)$(USER)$(X)-!"
	endif
endif

all: $(NAME)

$(NAME): $(AMLX) $(ALIBFT) $(SRCS) INC/cube.h
	$(CC) $(CFLAGS) $(SRCS) $(AMLX) $(ALIBFT) $(MFLAGS) -D NORMAL_SIZE=21 -o $(NAME) 

high: $(AMLX) $(ALIBFT) $(SRCS) INC/cube.h
	$(CC) $(CFLAGS) $(SRCS) $(AMLX) $(ALIBFT) $(MFLAGS)	-D HIGH_SIZE=21 -o $(NAME_H)

low: $(AMLX) $(ALIBFT) $(SRCS) INC/cube.h
	$(CC) $(CFLAGS) $(SRCS) $(AMLX) $(ALIBFT) $(MFLAGS)	-D LOW_SIZE=21 -o $(NAME_L)


$(AMLX):
	make -C $(MLX)

$(ALIBFT):
	make -C Others/libft

clean:
	rm -rf $(OBJS)
	make clean -C $(MLX)
	make clean -C Others/libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C Others/libft

re: fclean all

.PHONY: re clean fclean all high low sis
