NAME = cub3D

FLAGS = -Wall -Wextra -Werror

SRCS = main.c \
src/init/mock_map.c \
src/init/mlx_setup.c \
src/render/draw_frame.c \
src/render/raycast.c \
src/game/start_game.c \
src/game/handle_input.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I include ./libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	$(CC) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	rm -rf $(OBJS)

fclean:
	@make fclean -C libft
	@make clean -C minilibx-linux
	@rm -rf $(OBJS)
	@rm -rf $(NAME)

norme:
	norminette main.c cub3d.h srcs libft

re: fclean all

.PHONY: all re clean fclean
