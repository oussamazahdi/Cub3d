SRC			=	main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c utils/ft_strcmp.c \
				utils/ft_lstadd_back_bonus.c utils/ft_lstnew_bonus.c utils/ft_split.c utils/ft_atoi.c \
				utils/ft_strncmp.c\
				utils/utils1.c utils/ft_strshr.c\

OBJ			=	$(SRC:.c=.o)

CC			=	cc

FLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

NAME			=	cub3d

MLX_DIR		=	./MLX42  # Replace with your MLX42 path
#MLX_FLAGS		=	-I $(MLX_DIR)/include -L$(MLX_DIR)/build -lMLX42 -lglfw
MLX_FLAGS		=	-I./MLX42/include -L./MLX42/build -L/Users/ozahdi/.brew/opt/glfw/lib -lMLX42 -lglfw

all			:	$(NAME)

$(NAME)		:	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%o			:	%c cub3d.h
			$(CC) $(FLAGS) -c $< -o $@

clean		:
			rm -rf $(OBJ)
fclean		:	clean
			rm -rf $(NAME)

re			:	fclean all