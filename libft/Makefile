# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltrinchi <ltrinchi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 10:43:32 by ltrinchi          #+#    #+#              #
#    Updated: 2022/03/16 16:16:10 by ltrinchi         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_WITHOUT_PATH =	ft_atof.c \
					ft_atoi.c \
					ft_atol.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_free_tab_char.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isnum.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c

OBJS_WITHOUT_PATH = $(SRCS_WITHOUT_PATH:.c=.o)

PATH_TO_SRCS = ./srcs/
PATH_TO_OBJS = ./objs/

SRCS = $(addprefix $(PATH_TO_SRCS), $(SRCS_WITHOUT_PATH))
OBJS = $(addprefix $(PATH_TO_OBJS), $(OBJS_WITHOUT_PATH))

	##### COMMANDS ######
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
	#####################

	###### LIBFT ######
PATH_LIBFT = ./libft/
LIBFT_A = $(PATH_LIBFT)libft.a
	###################

	###### COLORS FOR PRINTF ######
GREEN 		= \033[0;32m
RED			= \033[0;91m
YELLOW      = \033[0;93m
WHITE       = \033[1;49;97m
	###############################

all: $(PATH_TO_OBJS) $(NAME)
	printf "$(GREEN)✅ $(NAME) is up to date$(WHITE) 👏\n"  

$(PATH_TO_OBJS):
	mkdir -p ./objs/

$(PATH_TO_OBJS)%.o: $(PATH_TO_SRCS)%.c Makefile ./srcs/libft.h
	printf "\033[2K\r$(YELLOW)⏳ Compiling:$(WHITE) $< 🤞\033[0m"  
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	printf "\n$(GREEN)✅ $(NAME) has been build 👍$(WHITE)\n"  

clean:
	$(RM) $(PATH_TO_OBJS)
	printf "$(RED)👌 Files has been deleted in $(PATH_TO_OBJS) ($(NAME))$(WHITE)\n"  
	printf "$(GREEN)✅ Clean 👍$(WHITE)\n"  

fclean: clean
	$(RM) $(NAME)
	printf "$(RED)👌 $(NAME) has been deleted$(WHITE)\n"  
	printf "$(GREEN)✅ Fclean 👍\033$(WHITE)\n"

re: fclean all

.PHONY: all clean fclean re rsc
.SILENT:
