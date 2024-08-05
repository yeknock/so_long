NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)

OBJFILE = objs

MLX = ./mlxLib

OBJS = $(patsubst srcs/%.c, $(OBJFILE)/%.o, $(SRCS))

RM = rm -rf

FMS = -lmlx -framework OpenGL -framework AppKit 

MD = mkdir -p

all: mlx $(OBJFILE) $(NAME)

$(OBJFILE) :
	@$(MD) $(OBJFILE)

$(OBJFILE)/%.o : srcs/%.c Makefile so_long.h
	@$(CC)  $(CFLAGS) -I$(MLX) -c $< -o $@

$(NAME): $(OBJS) Makefile
	@$(CC) $(OBJS) $(CFLAGS) -L$(MLX) $(FMS) -o $(NAME)

mlx:
	@make -s -C $(MLX) >/dev/null 2>&1

clean:
	@$(RM) $(OBJFILE)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
