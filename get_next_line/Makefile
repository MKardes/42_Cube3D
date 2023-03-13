NAME = get_next_line.a

all: $(NAME)
	@echo "Get_Next_Line DONE\n\n"

$(NAME): get_next_line.c get_next_line_utils.c
	gcc -c get_next_line.c -o a.o
	gcc -c get_next_line_utils.c -o b.o
	ar rcs $(NAME) *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf *.a

re: fclean all