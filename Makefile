SRC =	src/main.c \
	src/operation_push.c \
	src/operation_swap.c \
	src/utils.c \
	src/operation_rotate.c \
 	src/operation_rotate_rev.c	

OBJ = ${SRC:.c=.o}

NAME = push_swap

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

INCLUDE = -I./inc/push_swap.h

all: $(NAME)

$(NAME): ${OBJS}
	make -C ./libft
	cp libft/libft.a ${NAME}
	${CC} ${CFLAGS} ${INCLUDE} ${LIBFT} ${SRC} -o ${NAME}

clean: 
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf ${NAME}

re:	fclean all

.PHONY: make all clean fclean re