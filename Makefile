NAME    =   so_long

MLX_DIR	= ./mlx/

PATH_GNL = ./get_next_line/

GNL_FILES = get_next_line.c get_next_line_utils.c \

LIBFT_DIR	=	libft

LIBFT		=	$(LIBFT_DIR)/libft.a

SRC_DIR	= ./src/

INCLUDES = ./inc

SRC_FILES = draw_map.c end_game.c errors.c \
            movements.c so_long.c

CC      =    clang
FLAGS   =	-g -Wall -Wextra -Werror -I $(INCLUDES)
LIBS    = 	-L $(MLX_DIR) $(LIBFT) -lmlx -lXext -lX11 -lm

SRC_IMAGES	=	./img/

SRCS 		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
SRC_GNL		    =	$(addprefix $(PATH_GNL),$(GNL_FILES))
OBJS		=	$(SRCS:c=o)

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJS) 
			cd $(MLX_DIR) && ./configure
			$(CC) $(FLAGS) $(SRCS) $(SRC_GNL) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS deleted"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY = all clean fclean re