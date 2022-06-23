# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:14:06 by ycucchi           #+#    #+#              #
#    Updated: 2022/06/20 15:22:53 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ycucchi.filler

SRCS = filler.c map.c piece.c

SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

SRCS_DIR = ./srcs/

INCLUDES = -I ./includes/

LIBFT_PATH = ./libft/

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra #-Werror

CC = gcc

DEFAULT = \033[0;39m
GRAY = \033[0;90m
GREEN = \033[0;92m
CYAN = \033[0;96m

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) $(INCLUDES) $(SRCS_PATH) $(LIBFT) -o $(NAME)
	@echo "$(CYAN) $(NAME) compiled!$(DEFAULT)"

git:
	git add -A
	git commit -m "$m"
	git push

clean:
	@rm -rf filler.trace
	@echo "$(GRAY) filler.trace cleaned!$(DEFAULT)"
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"
	@make fclean -C $(LIBFT_PATH)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
