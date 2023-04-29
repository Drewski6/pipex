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
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

# ***** Sources *****

SRCS = pipex.c \
	pipex_utils_1.c \

SRCS_DIR = srcs/

# ***** Includes *****

INCS = pipex.h

INCS_DIR = includes/

# ***** Objects *****

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))

OBJS_DIR = objs/

# ***** Compile and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

LIBFT = -Llibft -lft

# ***** Build *****

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(OBJS_MAN)
	@echo -e -n ${GREEN}
	@make -C libft --silent
	@echo -e ===== MAKING PIPEX =====
	@echo -e -n ${NOCOLOR}
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c $(CFLAGS) -I$(INCS_DIR) $< -o $@

clean:
	@make -C libft clean --silent
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C libft fclean --silent
	@rm -f $(NAME)
	@rm -f gdb.txt

re: fclean all
