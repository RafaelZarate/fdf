

# NAME = 				fdf

# SRC = 				main.c \
# 					parsing.c \
# 					queue.c \
# 					utilities.c

# HDR =				fdf.h

# SRC_DIR =			src/
# SRC_FILES =			$(addprefix $(SRC_DIR), $(SRC_C))

# OBJ_DIR =			obj/
# OBJ_O =				$(SRC:.c=.o)
# OBJ_FILES =			$(addprefix $(OBJ_DIR), $(OBJ_O))

# LIBFT_DIR =			src/libft/
# LIBFT_A =			libft.a
# LIBFT_FILES =		$(addprefix $(LIBFT_DIR), $(LIBFT_A))

# LIBFT_HDR_DIR =		src/libft/includes/

# MLX =				minilibx/libmlx.a
# MLX_FLAGS =			-L minilibx -lmlx -framework OpenGL -framework AppKit

# HDR_DIR =			includes/
# HDR_FILES =			$(addprefix $(HDR_DIR), $(HDR))

# C_FLAGS =			-Wall -Wextra -Werror

# all: $(NAME)

# $(NAME): $(OBJ_FILES) $(LIBFT_FILES) $(MLX)
# 	@echo "$(NAME): Compiling $(NAME)..."
# 	@gcc $(C_FLAGS) $(MLX_FLAGS) $(OPT_FLAGS) $(P_THREAD) $^ -o $@
# 	@echo "$(NAME): Successfully compiled $(NAME)!"

# $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR_FILES)
# 	@mkdir -p obj
# 	@gcc $(C_FLAGS) -I $(HDR_DIR) -I $(LIBFT_HDR_DIR) -I minilibx -c $< -o $@

# $(LIBFT_FILES): force
# 	@make -C $(LIBFT_DIR)

# $(MLX): force
# 	@make -C minilibx

# force:
# 	@true

# clean:
# 	@echo "$(NAME): Cleaning objects..."
# 	@/bin/rm -rf $(OBJ_DIR)
# 	@make clean -C $(LIBFT_DIR) && make clean -C minilibx
# 	@echo "$(NAME): Successfully cleaned all objects!"

# fclean: clean
# 	@echo "$(NAME): Cleaning executable..."
# 	@/bin/rm -f $(NAME)
# 	@make fclean -C $(LIBFT_DIR)
# 	@echo "$(NAME): Successfully cleaned everything!"

# re:	fclean all

# .PHONY: all force clean fclean re



NAME =			fdf
LIBFT =			src/libft/
CFLAGS =		-Wall -Werror -Wextra
CC =			gcc
MLX =			minilibx/libmlx.a
MLX_FLAGS =		-I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit
MAKE = 			make -C

#When compiling. you need to add your .a lib
CFILES = 		$(LIBFT)/libft.a \
				$(MLX) \
				src/main.c \
				src/parsing.c \
				src/utilities.c \
				src/queue.c \
				src/image.c


#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIBFT)
LIBR = $(MAKE) $(LIBFT) re
LIBC = $(MAKE) $(LIBFT) clean
LIBF = $(MAKE) $(LIBFT) fclean

OBJECTS = $(CFILES:.c=.o)
all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -I includes/ $(MLX_FLAGS) -o $(NAME) $(CFILES)
	@echo "FDF: Successfull compilation"
	

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS) printf:.o
	@echo "FDF: Removed .o files"

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)
	@echo "FDF: Removed exacutable & .o files"

re: fclean all
