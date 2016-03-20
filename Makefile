# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bndao <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 07:37:14 by bndao             #+#    #+#              #
#    Updated: 2016/03/18 04:20:58 by bndao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS = -Wall
FLAGS += -Werror
FLAGS += -Wextra

SRCDIR = src/

SRC = $(SRCDIR)main.c \
		$(SRCDIR)tools.c \
		$(SRCDIR)list.c \

INC = header

OBJ = $(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L ./ft_printf -lftprintf
	@echo "\033[1;31m---- ft_ls Created !!! ----\033[0m"

%.o:%.c
	@gcc $(FLAGS) -c -o $@ $< -I $(INC) -I ft_printf/

lib:
	@echo "\033[1;32m-> Creating Library...\033[0m"
	@make -C ./ft_printf/

allclean: re clean

clean:
	@rm -f $(OBJ)
	@echo "\033[0;36m\nFT_LS Directory Cleaned up.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./ft_printf/

re: fclean all

.PHONY: $(NAME) all lib clean fclean re allclean
