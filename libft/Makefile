NAME = libft.a

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -I$(INC_DIR) 

SRC_DIR = src
SRCB_DIR = srcb
OBJ_DIR = obj
OBJB_DIR = objb
INC_DIR = include

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
SRCB_FILES = $(wildcard $(SRCB_DIR)/*.c)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
OBJB_FILES = $(patsubst $(SRCB_DIR)/%.c, $(OBJB_DIR)/%.o, $(SRCB_FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c
	@mkdir -p $(OBJB_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_FILES) $(OBJB_FILES)
	ar -crs $(NAME) $(OBJ_FILES) $(OBJB_FILES)

clean : 
	rm -rf $(OBJ_DIR) $(OBJB_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

norm :
	norminette src srcb libft.h

.PHONY: all clean fclean re