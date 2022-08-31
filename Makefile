SRC = main.c fdf.c get_next_line.c get_next_line_utils.c draw_map.c clean.c init.c get_seg.c

CC = gcc

HEADER = fdf.h libft/libft.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = fdf

RM = rm -rf

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror

LIBFT = @printf "\n\t\t${B_CYAN}GENERATE libft library ...\n\n${NONE}" && cd libft && make bonus && make all

MLX = @printf "\n\t\t${B_CYAN}GENERATE mlx library ...\n\n${NONE}" && cd minilibx-linux && make

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

./.build/%.o : %.c
	@$(CC) ${CFLAGS} -g -fsanitize=address -I. -o $@ -c $?
	@printf "${B_MAGENTA}Compilling $? ...\n${NONE}"

all :
	@mkdir -p .build
	@make ${NAME}

${NAME} : $(OBJ)
	${LIBFT}
	${MLX}
	@${CC} -o ${NAME} ${OBJ} -g -fsanitize=address libft/libft.a -L ./minilibx-linux -lmlx -lXext -lX11 \
	-lm
	@printf "${B_GREEN}==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

clean :
	@${RM} .build
	@printf "${B_RED}XX{${NAME}} CLEANED SUCCESFULLY XX${NONE}\n"

fclean :	clean
	@cd libft && make fclean
	@cd minilibx-linux && make clean
	@${RM} ${NAME}
	@printf "${B_RED}XX{${NAME}} FCLEAN SUCCESFULL XX${NONE}\n"

re :	fclean all
