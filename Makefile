# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 23:02:30 by iarslan           #+#    #+#              #
#    Updated: 2025/11/04 01:58:37 by iarslan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Dizinler ---
SRC_DIR     := src
INC_DIR     := include
LIBFT_DIR   := libft
MLX_DIR     := minilibx-linux
GNL_DIR     := get_next_line
PARSE_DIR   := $(SRC_DIR)/parsing
EXIT_DIR    := $(SRC_DIR)/exit

# --- İsimler ---
NAME        := cub3d
NAME_DEBUG  := cub3d_debug

# --- Araçlar ---
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
INCS        := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# --- Link bayrakları (Linux mlx) ---
MLX_LDFLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_LDFLAGS := -L$(LIBFT_DIR) -lft

# --- Kaynaklar (wildcard YOK; tek tek yazıldı) ---
SRC := \
	$(SRC_DIR)/main.c \
	$(PARSE_DIR)/main_parser.c \
	$(PARSE_DIR)/map_parser.c \
	$(PARSE_DIR)/header_parser.c \
	$(PARSE_DIR)/flood_fill.c \
	$(PARSE_DIR)/cpymap.c \
	$(PARSE_DIR)/parsing_utils.c \
	$(PARSE_DIR)/parsing_utils2.c \
	$(EXIT_DIR)/exit_1.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c

# Objeleri kaynaklardan türet (wildcard değil; pattern subst. serbest)
OBJ := $(SRC:.c=.o)

# ================= Targets =================

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(INCS) $(LIBFT_DIR)/libft.a $(MLX_LDFLAGS) -o $(NAME)

# --- Debug: -g ve -DDEBUG ile ayrı ikili ---
DEBUG_DIR := debug
EXTRA_DBG_OBJS := $(DEBUG_DIR)/debug.o

debug: CFLAGS += -O0 -g3 -DDEBUG
debug: $(OBJ) $(EXTRA_DBG_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(EXTRA_DBG_OBJS) $(INCS) $(LIBFT_DIR)/libft.a $(MLX_LDFLAGS) -o $(NAME_DEBUG)

$(DEBUG_DIR)/debug.o: $(DEBUG_DIR)/debug.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


# --- Derleme kuralı (TEK TAB ile başlar) ---
%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean || true
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean || true
	$(RM) $(NAME) $(NAME_DEBUG)

re: fclean all

.PHONY: all debug clean fclean re
