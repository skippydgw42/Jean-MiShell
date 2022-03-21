NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER =	\
			./includes/pipex.h		\

PARSING =	\
			./parsing/parsing.c		\

ADD =	\
		./add/err.c					\
		./add/flags.c				\
		./add/free.c				\
		./add/utils.c				\
		./add/close.c				\

INIT =	\
		./init/get_things.c			\
		./init/init.c				\
		./init/pipe.c				\

SRCS =	\
		./srcs/main.c				\
		./srcs/pipex.c				\
		${PARSING}					\
		${INIT}						\
		${ADD}						\

OBJS = ${SRCS:.c=.o}
OBJS_BON = ${BONUS:.c=.o}

LIB = ./libft/libft.a

all :	library ${NAME}

library :
	make -C ./libft

%.o :	%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME} :	${OBJS} ${LIB}
	${CC} ${OBJS} ${LIB} -o ${NAME}

bonus :		${NAME} 
clean :
	make -C ./libft clean
	/bin/rm -f ${OBJS}

fclean :	clean
	/bin/rm -f libft/libft.a
	/bin/rm -f ${NAME}

re :	fclean all

.PHONY :	all library clean fclean re
