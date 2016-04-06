# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bndao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 07:37:14 by bndao             #+#    #+#              #
#    Updated: 2016/03/22 02:04:22 by bndao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall
FLAGS += -Werror
FLAGS += -Wextra

SRCDIR = src/

SRC = $(SRCDIR)main.c \
		$(SRCDIR)errors.c \
		$(SRCDIR)initav_list.c \
		$(SRCDIR)spaces.c \
		$(SRCDIR)rights.c \
		$(SRCDIR)print.c \
		$(SRCDIR)display.c \
		$(SRCDIR)get.c \
		$(SRCDIR)tools.c \
		$(SRCDIR)list.c \
		$(SRCDIR)mergesort.c \
		$(SRCDIR)parse_it.c \
		$(SRCDIR)direcursive.c \

INC = header

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L ./libft -lftprintf
	@echo "\033[1;31m---- ft_ls Created !!! ----\033[0m"

%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I libft/

lib:
	@echo "\033[1;32m-> Creating Library...\033[0m"
	@make -C ./libft/

clean:
	@rm -f $(OBJ)
	@echo "\033[0;36m\nFT_LS Directory Cleaned up.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

allclean: re clean

.PHONY: $(NAME) all lib clean fclean re allclean
