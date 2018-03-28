# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/03/28 09:49:22 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : man norme all clean fclean re

NAME = fdf

FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBXL = -lm -L/usr/lib/X11 -lmlx -lXext -lX11

MAIN_FUNCS = ft_open_window.c \
			 ft_draw.c \
			 ft_line.c \
			 ft_newpoint.c \
			 ft_point.c \
			 ft_circle.c \
			 ft_lector.c \
			 ft_equline.c \
			 ft_pendant.c \
			 ft_rotatepoint.c \
			 ft_clear.c \
			 ft_iniparams.c \
			 ft_coder.c \
			 ft_get_color.c \
			 main.c

LIBFT_NAME = libft.a

LIBFT_ABREV = ft

LIBFT_DIR = libft/

OBJ_DIR = objects/

MAINS_DIR = srcs/

MAINS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))

OBJ = $(MAINS_OBJ)

INCLUDES_DIR = includes/

INCLUDES_MLX = /usr/local/include

all : $(NAME)

$(NAME) : $(MAINS_OBJ) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(OBJ) -L $(LIBFT_DIR) -l$(LIBFT_ABREV) -lftprintf -I $(INCLUDES_DIR) $(FLAGS) -o $(NAME)

$(LIBFT_DIR)$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)%.o : $(MAINS_DIR)%.c
	gcc -c -I $(INCLUDES_DIR) $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

clean:
	rm -f $(OBJ_SRC)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	make

man:
	man /usr/share/man/man3/mlx.1

man_window:
	man /usr/share/man/man3/mlx_new_window.1
