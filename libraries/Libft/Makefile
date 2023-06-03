# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcrispol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 16:35:55 by pcrispol          #+#    #+#              #
#    Updated: 2023/03/07 16:35:58 by pcrispol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftcompleta.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
       ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
       ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_printf.c \
       ft_printf_utils.c ft_printf_utils2.c ft_print_p.c ft_print_u.c ft_print_x.c \
       ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
       ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
       ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
       ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c \
       

BONUS = 

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
