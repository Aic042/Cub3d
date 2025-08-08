NAME	= so_long
LIBMLX	= lib/MLX42
LIBFT	= lib/libft

CFLAGS = -Wextra -Wall -Werror -Ofast -g
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS = -L$(LIBFT) -L$(LIBMLX)/build -lmlx42 -lglfw
SRCS := $(shell find ./src -iname "*.c")
OBJS := $(SRCS:.c=.o)

# Colors
GREEN  := \033[1;32m
YELLOW := \033[1;33m
BLUE   := \033[1;34m
RED    := \033[1;31m
RESET  := \033[0m

all: banner loading libmlx libft $(NAME) fun_msg

banner:
	@echo "$(BLUE)"
	@echo "███████╗ ██████╗      ██╗      ██████╗ ███╗   ██╗ ██████╗ "
	@echo "██╔════╝██╔═══██╗     ██║     ██╔═══██╗████╗  ██║██╔═══██╗"
	@echo "███████╗██║   ██║     ██║     ██║   ██║██╔██╗ ██║██║   ██║"
	@echo "╚════██║██║   ██║     ██║     ██║   ██║██║╚██╗██║██║   ██║"
	@echo "███████║╚██████╔╝     ███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
	@echo "╚══════╝ ╚═════╝      ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ "
	@echo "$(RESET)"

loading:
	@echo -n "Building"; for i in {1..3}; do sleep 0.3; echo -n "."; done; echo " 🚀"

libmlx:
	@echo "$(YELLOW)🔧 Building MLX42...$(RESET)"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "$(YELLOW)🔧 Building libft...$(RESET)"
	@make -C $(LIBFT)

%.o: %.c
	@echo "$(BLUE)🛠️  Compiling $< $(RESET)"
	cc $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)🔗 Linking $(NAME)...$(RESET)"
	cc $(OBJS) -L$(LIBFT) -lft -L$(LIBMLX)/build -lmlx42 -lglfw -o $(NAME)

fun_msg:
	@echo "$(GREEN)$(shell shuf -n 1 -e 'Build complete! 🚀' 'Time to play! 🎮' 'so_long is ready! ✅')$(RESET)"

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)🔥 Full clean in progress...$(RESET)"
	@rm -rf $(NAME)	
	@rm -rf $(LIBMLX)/build

re: fclean all

.PHONY: all bonus clean fclean re libmlx libft % 