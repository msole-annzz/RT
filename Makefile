NAME = RTv1

SRCS =  ./sources/main.c\
		./sources/keys.c\
		./sources/vector_operations.c\
		./sources/rotation.c\
		./sources/figures.c\
		./sources/traceray.c\
		./sources/color.c\
		./sources/intersectobj.c\
		./sources/lights.c\
		./sources/quadrsol.c\
		./sources/threads.c\
		./sources/parsing/read_file.c\
        ./sources/parsing/check_file.c\
        ./sources/parsing/tools.c\
        ./sources/parsing/tools_objects.c\
        ./sources/parsing/tools_lights.c\
        ./sources/parsing/tools_read.c\
        ./sources/parsing/errors.c\
        ./sources/parsing/parsing.c\
        ./sources/parsing/parsing_lights.c\
        ./sources/parsing/parsing_objects.c\
        ./sources/parsing/malloc_free.c\

OB = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

INCLUDES = -I $(HEADER_DIR) -I $(LIBFT_PATH)

HEADER_DIR = ./includes/
HEADER_LIST = rtv1.h keys.h structs.h parsing.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT = libft/libft.a
LIBFT_PATH = libft
MINILIBX = ./minilibx/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean clean re

all: $(NAME)
$(NAME): $(LIBFT) $(OB) $(HEADER)
	gcc $(FLAG) $(OB) -o $(NAME) -L $(LIBFT_PATH) -lft -L $(MINILIBX) -lpthread

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

%.o: %.c $(HEADER)
	@gcc $(FLAG) $(INCLUDES) -c $< -o $@
clean:
	@/bin/rm -f $(OB)
	@$(MAKE) -C $(LIBFT_PATH) clean
fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
re: fclean all


# -L $(MINILIBX) -lpthread
