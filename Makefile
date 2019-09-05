# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 12:41:11 by sgauguet          #+#    #+#              #
#    Updated: 2019/06/20 12:49:07 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
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

SRCS_DIR =			./src

OBJS_DIR =			./objs

HEADERS_DIR =		./includes

LIB_DIR =			./libft

LIB_HEADERS_DIR =	./libft/includes

#------------------------------------------------------------------------------#
# Sources

SRCS =			main.c \
				inspect_file.c \
				opt_parse.c \
				arg_parse.c \
				print_list.c \
				list_repository.c \
				sort.c

OBJS =			$(SRCS:%.c=$(OBJS_DIR)/%.o)

HEADERS =		$(HEADERS_DIR)/ft_ls.h 

#------------------------------------------------------------------------------#
# Compilation

NAME =			ft_ls

CC =			gcc -g

FLAGS =			-Wall \
				-Wextra \
				-Werror \
				#-fsanitize=address

HEADERS_FLAGS =	-I $(HEADERS_DIR) \
				-I $(LIB_HEADERS_DIR)

LIB_FLAGS =		-L $(LIB_DIR) -lft

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

$(NAME): $(OBJS)
	make -C $(LIB_DIR) all
	@$(CC) -g $(ALL_FLAGS) $^ -o $@ $(LIB_FLAGS)
	@echo "$(GREEN)Executable created : $(RES)" $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS)
	@echo "$(GREEN)--- Compilation ---$(RES)";
	@mkdir -p $(OBJS_DIR)
	@echo "$(GREEN)Objects created : $(RES)" $@
	@$(CC) $(ALL_FLAGS) -o $@ -c $<

clean:
	make -C $(LIB_DIR) clean
	@echo "$(RED)--- objects removed ---$(RES)";
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "$(RED)--- executable removed ---$(RES)";
	@rm -rf $(LIB_DIR)/libft.a
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

#------------------------------------------------------------------------------#
# Git

git:
	@git add Makefile $(SRCS_DIR) $(HEADERS_DIR) auteur

.PHONY: all clean fclean re git

