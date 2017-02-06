NAME = rtv1

SRC_PATH = srcs

SRC_NAME =	class_ray.c\
			class_vector.c\
			destroy_env.c\
			draw.c\
			event.c\
			getter_camera.c\
			init_env.c\
			init_scene.c\
			init_window.c\
			main.c\
			parser_camera.c\
			parser_light.c\
			parser_object.c\
			parser_scene.c\
			parser_toolbox.c\
			parser_window.c\
			setter_camera.c\

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = ./objs
INC_PATH = ./includes
LFT_PATH = ./libft
MLX_PATH =

CC = gcc -g
CFLAGS = -Werror -Wextra -Wall
LDFLAGS = -L$(LFT_PATH)
LDLIBS = -lft -lmlx -lm -lpthread

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	MLX_PATH += ./minilibx/osx
	LDFLAGS += -L$(MLX_PATH)
	LDLIBS += -framework AppKit -framework OpenGL
endif

ifeq ($(UNAME),Linux)
	MLX_PATH += ./minilibx/linux
	LDFLAGS += -L$(MLX_PATH)
	LDLIBS += -lX11 -lXext
endif

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_PATH)
	-make -C $(MLX_PATH)
	$(CC) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $< -I$(INC_PATH) -I$(LFT_PATH) -I$(MLX_PATH)

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	make -C $(LFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	rm -fv $(NAME)
	make -C $(LFT_PATH) fclean
	make -C $(MLX_PATH) clean

re:	fclean all
