# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -ggdb

# Directories
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = libft
OBJ_DIR = obj

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Include directories
INCLUDES = -I$(INCLUDE_DIR)

# Links
# LINKS = -I $(LIB_DIR) -L $(LIB_DIR) \
#     -I $(INCLUDE_DIR) -L $(INCLUDE_DIR) \
#     -lmlx -lft

LINKS = -lft -L libft \
    $(INCLUDES) -L $(INCLUDE_DIR) \
    -l mlx -framework OpenGL -framework Appkit -Imlx_linux -O3 

ifeq ($(shell uname), Darwin)
    LINKS += -framework OpenGL -framework Appkit
endif

# Target executable
NAME = so_long

# Default target
all: $(NAME)
	clear

# Rule to build the executable
$(NAME): $(OBJS) libft
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) $(OBJS) $(LINKS) -o $@

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean
	clear

# Clean rule with target executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean
	clear

# Rebuild rule
re: fclean all