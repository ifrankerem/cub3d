# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 02:30:48 by iarslan           #+#    #+#              #
#    Updated: 2025/10/24 02:50:08 by iarslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR     := src
INC_DIR     := include
LIBFT_DIR   := libft
MLX_DIR     := minilibx-linux

NAME        := cub3d

CC          := cc
CFLAGS      := -g -Wall -Wextra -Werror #look for -g flag
INCS        := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

MLX_LDFLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_LDFLAGS := -L$(LIBFT_DIR) -lft

SRC := training.c\
# 	$(SRC_DIR)/main.c \
# 	$(SRC_DIR)/

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(INCS) $(LIBFT_DIR)/libft.a $(MLX_LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean || true
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re