CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -g3

HEADERS = cub3d.h

SOURCES = main.c gestion.c init.c utils.c 
SRC = srcs/
DIR = objs_deps/
INC = includes/

INCLUDES = -I/$(INCS)

SRCS = $(addprefix $(SRC), $(SOURCES))
OBJS = $(addprefix $(DIR), $(OBJ))
DEPS = $(addprefix $(DIR), $(DEP))
INCS = $(addprefix $(INC), $(HEADERS))

OBJ = $(SOURCES:.c=.o)
DEP = $(SOURCES:.c=.d)

NAME = cub3D

all : $(NAME)

$(NAME) : $(OBJS)
	@make -sC minilibx-linux
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) minilibx-linux/libmlx.a -lX11 -lXext -lbsd
	@echo "Compilation completed"

$(DIR)%.o : $(SRC)%.c | $(DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(DIR) :
	@echo "Start Compilation for $(NAME)"
	@echo "Wait ..."
	@mkdir -p objs_deps
	@mkdir -p objs_deps/builtin
	@mkdir -p objs_deps/env
	@mkdir -p objs_deps/exec
	@mkdir -p objs_deps/expend
	@mkdir -p objs_deps/parsing

clean :
	@echo "Deleting Objects and Dependencies"
	@make clean -sC minilibx-linux
	@rm -rf $(DIR)

fclean : clean
	@echo "Deleting the executable"
	@rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : all bonus clean fclean re