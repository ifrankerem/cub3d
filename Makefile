# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 23:02:30 by iarslan           #+#    #+#              #
#    Updated: 2025/12/27 16:39:32 by bucolak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Dizinler ---
SRC_DIR     := src
INC_DIR     := include
LIBFT_DIR   := libft
MINILIBX_DIR := minilibx-linux
GNL_DIR     := get_next_line
PARSE_DIR   := $(SRC_DIR)/parsing
EXIT_DIR    := $(SRC_DIR)/exit
MLX_SRC_DIR := $(SRC_DIR)/mlx
RAYCAST_DIR := $(SRC_DIR)/raycast

# --- İsimler ---
NAME        := cub3d

# --- Araçlar ---
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCS        := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

# --- Link bayrakları (Linux mlx) ---
MLX_LDFLAGS := -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_LDFLAGS := -L$(LIBFT_DIR) -lft

# --- Kaynaklar (wildcard YOK; tek tek yazıldı) ---
SRC := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/inits/player_initialization.c \
	$(SRC_DIR)/inits/init.c \
	$(PARSE_DIR)/main_parser.c \
	$(PARSE_DIR)/map_parser.c \
	$(PARSE_DIR)/header_parser.c \
	$(PARSE_DIR)/i_load.c \
	$(PARSE_DIR)/load_tex.c \
	$(PARSE_DIR)/valid_map_control.c \
	$(PARSE_DIR)/flood_fill.c \
	$(PARSE_DIR)/cpymap.c \
	$(PARSE_DIR)/control_playable.c \
	$(PARSE_DIR)/rgb_load.c \
	$(PARSE_DIR)/parsing_utils.c \
	$(PARSE_DIR)/parsing_utils2.c \
	$(PARSE_DIR)/is_map_close.c \
	$(PARSE_DIR)/xpm_control.c \
	$(EXIT_DIR)/exit_first.c \
	$(EXIT_DIR)/exit_scnd.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c \
	$(MLX_SRC_DIR)/mlx.c \
	$(MLX_SRC_DIR)/key_actions.c \
	$(RAYCAST_DIR)/3D/3d.c \
	$(RAYCAST_DIR)/draw.c \
	$(RAYCAST_DIR)/calculate_FPS.c \
	$(MLX_SRC_DIR)/movement.c \
	$(RAYCAST_DIR)/raycast.c \
	$(RAYCAST_DIR)/raycast_scnd.c
	

# Objeleri kaynaklardan türet (wildcard değil; pattern subst. serbest)
OBJ := $(SRC:.c=.o)

# ================= Targets =================

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(INCS) $(LIBFT_DIR)/libft.a $(MLX_LDFLAGS) -o $(NAME)

# --- Derleme kuralı (TEK TAB ile başlar) ---
%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean || true
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	$(RM) $(NAME)

re: fclean all

.PHONY: all  clean fclean re
