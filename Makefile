

NAME			= so_long

GREEN			= \033[0;32m
RED			= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./libraries/Libft/libftcompleta.a

CC 			= clang

STANDARD_FLAGS 		= -g
MINILIBX_FLAGS		= minilibx-linux/libmlx.a -lX11 -lXext -lm

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./sources/

SRCS 			= so_long.c	checkmap.c
			

all:			${LIBFT} ${NAME}

${NAME}: 		
			${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
			@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
			@echo

${LIBFT}:
			@echo
			make bonus -C libraries/Libft

clean:
			make clean -C libraries/Libft
			@echo

fclean:
			${REMOVE} ${NAME} ${NAME_BONUS}
			@echo "${NAME}: ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"
			@echo

re:			fclean all

run:			${NAME}
			${VALGRIND} ./${NAME} assets/maps/valid/map4.ber

.PHONY:			all clean fclean re valgrind run
