LIBFT_PATH = ./libft

LIBFT_SRC = ${addprefix ${LIBFT_PATH}/, ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strlen.c ft_strlcpy.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strlcat.c ft_strnstr.c ft_strdup.c \
			ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_strjoin.c ft_substr.c ft_strtrim.c \
			ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstiter.c ft_lstmap.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c }

PRINTF_PATH = ./printf

PRINTF_SRC = ${addprefix ${PRINTF_PATH}/, ft_printf.c ft_putchar.c ft_putstr.c  ft_putnbr.c ft_puthex_low.c ft_puthex_upp.c ft_putptr.c ft_uputnbr.c ft_puthex_ptr.c}


SRCS = ${LIBFT_SRC} ${PRINTF_SRC}

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

INCLUDE = ./inc

%.o:%.c ${INCLUDE}
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

NAME = libft.a

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "COMPILED ${NAME}"

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re