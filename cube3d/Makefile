.SILENT:

MAKEFLAGS	+=	--silent

NAME		:=	cub3D

CC			:=	gcc

CFLAGS		:=	-g -Wall -Wextra -Werror

MLXFLAGS	:=	-L minilibx-linux -lmlx -lm -lXext -lX11

LIBFT		:=	Libft/libft.a

OBJS_DIR	:=	obj/

SRCS_DIR	:=	srcs/

SRCS		:=	main.c				\
				start_game.c		\
				key_handler.c		\
				quit_game.c			\
				map.c				\
				check_textures.c	\
				check_textures2.c	\
				info_game.c			\
				check_map.c			\
				open_map.c			\
				init_datas.c		\
				draw.c				\
				player_info.c		\
				general_utils.c		\
				iskey.c				\
				wasd_movement.c		\
				arrow_movement.c	\
				raycasting.c		\
				raycasting_2.c

OBJS		:=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# COLORS ================================================================= #

RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
WHITE	=	\033[0;97m

# ======================================================================== #

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): lib $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}"

lib:
	@make -C Libft

clean:
	@rm $(OBJS)
	@make clean -C Libft
	@echo "$(RED)All object files removed.$(WHITE)"

fclean: clean
	@rm -rf $(NAME) $(OBJS_DIR)
	@make fclean -C Libft

re:	fclean all

.PHONY:	all clean fclean re lib
