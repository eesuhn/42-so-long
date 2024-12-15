NAME = so_long

MAKE = make --no-print-directory
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs/
OBJDIR = objs/
SRC_FILES = \
			check \
			check2 \
			draw \
			exit \
			init \
			keys \
			main \
			movement \
			parser \
			textures \
			utils \
			validate \
			validate2 \

SRCS = $(addprefix $(SRCDIR), $(SRC_FILES:=.c))
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = mlx-linux
MLX = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "\033[0;32mDone!\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@echo "> $<"
	@$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(MLX):
	@echo "Compiling minilibx..."
	@$(MAKE) -C $(MLX_PATH) > /dev/null 2>&1

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@echo "\033[0;33mCleaning...\033[0m"
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean > /dev/null 2>&1
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
