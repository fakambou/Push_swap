SRCS = $ main.c parcing.c utils.c rotate.c swap.c reverse_rotate.c push.c small_sort.c big_sort.c utils2.c utils3.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./libft

all : ${NAME}

${NAME}:${OBJS}
	${MAKE} -C ${LIBFT}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}/libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re