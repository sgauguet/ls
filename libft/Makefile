# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 22:52:43 by sgauguet          #+#    #+#              #
#    Updated: 2018/02/21 09:50:38 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

BLACK =		\033[1;30m
RED =		\033[1;31m
GREEN =		\033[1;32m
YELLOW =	\033[1;33m
BLUE =		\033[1;34m
PINK =		\033[1;35m
CYAN =		\033[1;36m
GREY =		\033[1;37m
RES =		\033[0m

#------------------------------------------------------------------------------#
# Folders

SRCS_DIR =			.

SRCS_PRINTF_DIR =	./printf

OBJS_DIR =			./objs

OBJS_PRINTF_DIR =	./objs/printf

HEADERS_DIR =		.

#------------------------------------------------------------------------------#
# Sources

SRCS = 	ft_memset.c \
	  	ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_atoll.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_itoa_base_2.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_is_negative.c \
		ft_swap.c \
		ft_isblank.c \
		ft_islower.c \
		ft_isupper.c \
		ft_div_mod.c \
		get_next_line.c \
		ft_strtolower.c \
		ft_strcasecmp.c

SRCS_PRINTF = printf.c \
		check.c \
		types.c \
		search_flags.c \
		print_flags.c \
		field_width.c \
		conversions_1.c \
		conversions_2.c \
		conversions_3.c \
		conversions_4.c \
		bonus_conversions.c \
		wchar.c

OBJS =			$(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_PRINTF =	$(SRCS_PRINTF:%.c=$(OBJS_PRINTF_DIR)/%.o)

HEADERS =		$(HEADERS_DIR)/libft.h 

#------------------------------------------------------------------------------#
# Compilation

NAME =			libft.a

CC =			gcc

FLAGS =			-Wall \
				-Wextra \
				-Werror \
				#-fsanitize=address

HEADERS_FLAGS =	-I $(HEADERS_DIR)

ALL_FLAGS =		$(FLAGS) \
				$(HEADERS_FLAGS)

# Automatic Variables :
# $@	Le nom de la cible
# $^	La liste des dépendances
# $<	Le nom de la première dépendance
# $?	La liste des dépendances plus récentes que la cible
# $*	Le nom du fichier sans suffixe
#------------------------------------------------------------------------------#

all: $(NAME)

.SILENT:

$(NAME): $(OBJS) $(OBJS_PRINTF)
	@echo "$(GREEN)Library created : $(RES)" $@
	ar rc $(NAME) $(OBJS) $(OBJS_PRINTF)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJS_PRINTF_DIR)
	@echo "$(GREEN)Objects created : $(RES)" $@
	@$(CC) $(ALL_FLAGS) -o $@ -c $<

$(OBJS_PRINTF_DIR)/%.o: $(SRCS_PRINTF_DIR)/%.c $(HEADERS)
	@echo "$(GREEN)Objects created : $(RES)" $@
	@$(CC) $(ALL_FLAGS) -o $@ -c $<

clean:
	@echo "$(RED)--- objects removed ---$(RES)";
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(RED)--- executable removed ---$(RES)";
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re git


