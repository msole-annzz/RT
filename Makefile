NAME = RT

CC = gcc -g

SRCS =  main.c\
		keys.c\
		mouse.c\
		vector_operations.c\
		rotation.c\
		figures.c\
		traceray.c\
		color.c\
		intersectobj.c\
		lights.c\
		quadrsol.c\
		threads.c\
		ft_reflection_color.c\
		color_functions.c\
		sources/parsing/read_file.c\
		sources/parsing/check_file.c\
		sources/parsing/tools.c\
		sources/parsing/tools_objects.c\
		sources/parsing/tools_lights.c\
		sources/parsing/tools_read.c\
		sources/parsing/errors.c\
		sources/parsing/parsing.c\
		sources/parsing/parsing_lights.c\
		sources/parsing/parsing_objects.c\
		sources/parsing/malloc_free.c\
		sources/parsing/check_parsing_DELETE_ME.c

SRC_FILE = $(notdir $(SRCS))

OBJECTS_DIR = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC_FILE))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

FLAG = -Wall -Wextra -Werror

INCLUDES = -I $(HEADER_DIR) -I $(LIBFT_PATH)

HEADER_DIR = ./includes/
HEADER_LIST = rt.h keys.h structs.h parsing.h
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

LIBFT = libft/libft.a
LIBFT_PATH = ./libft
MINILIBX = -L ./minilibx/ -lmlx -framework OpenGL -framework AppKit

vpath %.c ./sources/
vpath %.c ./sources/parsing/
#vpath %.c ./minilibx/
vpath %.h ./includes/

.PHONY: all clean clean re FAKE

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS_DIR) $(OBJECTS)
	@gcc $(FLAG) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH) -lft $(MINILIBX)
	@echo "\n✅\033[33m$(NAME):\033[32m was created\033[0m"

$(OBJECTS_DIR):
		@mkdir -p $(OBJECTS_DIR)
		@echo "\n✅\033[33m$(NAME):\033[32m $(OBJECTS_DIR)directory was created\033[0m"

$(OBJECTS_DIR)%.o: %.c $(HEADER)
		@$(CC) $(FLAGS) -c $(INCLUDES) -o $@ $<
		@echo "✅\c"

$(LIBFT): FAKE
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@/bin/rm -rf $(OBJECTS_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all


# -L $(MINILIBX) -lpthread
