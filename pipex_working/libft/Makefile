# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:36:56 by dpentlan          #+#    #+#              #
#    Updated: 2023/04/29 11:56:05 by dpentlan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME = libft.a

# ***** Sources *****

SRCS =	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	
BONUS_SRCS =	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

GNL_SRCS = get_next_line_bonus.c \
	ft_strjoin_gnl.c \

FT_PRINTF_SRCS = ft_printf_bonus.c \
	ft_printf_utils_1_bonus.c \
	ft_printf_utils_2_bonus.c \
	ft_printf_utils_3_bonus.c \
	ft_printf_utils_format_switch_bonus.c \
	ft_printf_utils_subseq_helpers_bonus.c \
	ft_printf_utils_t_flags_bonus.c \
	ft_printf_utils_use_flags_bonus.c

SRCS_DIR = srcs/
BONUS_SRCS_DIR = srcs/
GNL_SRCS_DIR = srcs/
FT_PRINTF_SRCS_DIR = srcs/

# ***** Includes *****

INCS = libft.h

INCS_DIR = includes/

# ***** Objects *****

ALL_OBJS = $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)

OBJS = $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))
BONUS_OBJS = $(patsubst %.c,$(BONUS_OBJS_DIR)%.o,$(BONUS_SRCS))
GNL_OBJS = $(patsubst %.c,$(GNL_OBJS_DIR)%.o,$(GNL_SRCS))
FT_PRINTF_OBJS = $(patsubst %.c,$(FT_PRINTF_OBJS_DIR)%.o,$(FT_PRINTF_SRCS))

OBJS_DIR = objs/
BONUS_OBJS_DIR = objs/
GNL_OBJS_DIR = objs/
FT_PRINTF_OBJS_DIR = objs/

# ***** Compiler and Archiver *****

CFLAGS = -Wall -Wextra -Werror -g
CC = cc
SLIB = ar rcs

# ***** Build *****

all: $(NAME)

$(NAME): $(ALL_OBJS)
	@echo "===== MAKING LIBFT ====="
	@$(SLIB) $(NAME) -o $(ALL_OBJS)

m: $(OBJS)
	@echo "===== MAKING LIBFT MANDATORY ONLY ====="
	@$(SLIB) $(NAME) -o $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	@echo "===== MAKING LIBFT BONUS ONLY ====="
	@$(SLIB) $(NAME) -o $(OBJS) $(BONUS_OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -I$(INCS_DIR) $< -o $@

$(BONUS_OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c
	@mkdir -p $(BONUS_OBJS_DIR)
	@$(CC) $(CFLAGS) -c -I$(INCS_DIR) $< -o $@

$(GNL_OBJS_DIR)%.o: $(GNL_SRCS_DIR)%.c
	@mkdir -p $(GNL_OBJS_DIR)
	@$(CC) $(CFLAGS) -c -I$(INCS_DIR) $< -o $@

$(FT_PRINTF_OBJS_DIR)%.o: $(FT_PRINTF_SRCS_DIR)%.c
	@mkdir -p $(FT_PRINTF_OBJS_DIR)
	@$(CC) $(CFLAGS) -c -I$(INCS_DIR) $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS) $(GNL_OBJS) $(FT_PRINTF_OBJS)
	@rm -rf $(OBJS_DIR)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
