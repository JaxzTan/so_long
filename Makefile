NAME = so_long

CC = gcc

INCLUDE = -Linclude

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard src/*.c)

OBJ_SRC = $(SRC:.c=.o)

ifeq ($(shell uname), Linux)
	MINILIBX = minilibx-linux/
	MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	MINILIBX = minilibx/
	MINILIBX_LIBRARY = -L$(MINILIBX) -lmlx -framework OpenGL -framework AppKit
endif

all: $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ_SRC)
	make -C $(MINILIBX)
	make -C libft
	cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJ_SRC) $(INCLUDE) libft.a $(MINILIBX_LIBRARY) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C $(MINILIBX)
	rm -rf $(OBJ_SRC)
	rm -rf obj
	rm -f libft.a

fclean : clean
	rm -f $(NAME)
	make fclean -C libft
	
re : fclean all

.PHONY : all clean fclean re