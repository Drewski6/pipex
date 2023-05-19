# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 14:27:11 by dpentlan          #+#    #+#              #
#    Updated: 2023/04/29 12:19:40 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS= pipex_bonus
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

# ***** Sources *****

SRCS = pipex.c \
	pipex_utils_1.c \
	pipex_utils_2.c \
	pipex_path_utils_1.c \
	pipex_fork_utils_1.c \
	pipex_list_utils_1.c \

SRCS_DIR = mandatory/srcs/

SRCS_BONUS = pipex_bonus.c \
	pipex_bonus_utils_1.c \
	pipex_bonus_utils_2.c \
	pipex_bonus_path_utils_1.c \
	pipex_bonus_fork_utils_1.c \
	pipex_bonus_list_utils_1.c \

SRCS_DIR_BONUS = bonus/srcs/

# ***** Includes *****

INCS = pipex.h

INCS_DIR = mandatory/includes/

INCS_BONUS = pipex_bonus.h

INCS_DIR_BONUS = bonus/includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR = mandatory/objs/

OBJS_BONUS = $(patsubst %.c,$(OBJS_DIR_BONUS)%.o,$(SRCS_BONUS))

OBJS_DIR_BONUS = bonus/objs/

# ***** Compile and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

LIBFT = -Llibft -lft

# ***** Build *****

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	@echo -e -n ${GREEN}
	@make -C libft --silent
	@echo -e ===== MAKING PIPEX =====
	@echo -e -n ${NOCOLOR}
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS): $(OBJS_BONUS)
	@echo -e -n ${GREEN}
	@make -C libft --silent
	@echo -e ===== MAKING PIPEX BONUS =====
	@echo -e -n ${NOCOLOR}
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) -I$(INCS_DIR) $< -o $@

$(OBJS_DIR_BONUS)%.o: $(SRCS_DIR_BONUS)%.c
	@mkdir -p $(OBJS_DIR_BONUS)
	@$(CC) -c $(CFLAGS) -I$(INCS_DIR_BONUS) $< -o $@

clean:
	@make -C libft clean --silent
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)
	@rm -f $(OBJS_BONUS)
	@rm -rf $(OBJS_DIR_BONUS)

fclean: clean
	@make -C libft fclean --silent
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@rm -f gdb.txt

re: fclean all
