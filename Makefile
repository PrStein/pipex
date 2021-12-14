NAME = push_swap

CC = clang

FLAGS    = -Wall -Wextra -Werror -g

DEL = /bin/rm -f

SRCS =     

SRCS_O    = ${SRCS:.c=.o}
all: $(NAME)

LIBC    = ar -rcs

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
			make bonus -C ./libft/
		 $(CC) $(FLAGS) $(SRCS_O) -o $(NAME) -L ./libft/ -lft

fclean: clean
		$(DEL) $(NAME)
		make fclean -C ./libft/

clean:
		$(DEL) $(SRCS_O)
		make clean -C ./libft/

re: fclean all
