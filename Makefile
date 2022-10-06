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
FILES =  algo_helper.c algo.c clean.c filler.c grid.c piece.c solver.c \
solver_help.c struct.c
SRCS_PATH = ./srcs/
INCL	=	-I ./includes
INCL_LFT=	-I ./libft/includes
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a
LIB_LFT = -L ./libft/ -lft
CCFLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(SRCS:.c=.o)
OBJ_DIR = ./objects/
CC = gcc
DEFAULT = \033[0;39m
GRAY = \033[0;90m
GREEN = \033[0;92m
CYAN = \033[0;96m

all: $(NAME)

$(LIBFT) :
	make -C $(LIBFT_PATH)

$(OBJ_DIR)%.o:$(SRC_PATH)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCL_LFT) $(INCL) -c -o $@ $<

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(INCL_LFT) $(INCL) $(OBJS) $(LIB_LFT)

git:
	git add -A
	git commit -m "$m"
	git push

clean:
	@rm -rf filler.trace
	@echo "$(GRAY)filler.trace cleaned!$(DEFAULT)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GRAY)$(OBJ_DIR) cleaned!$(DEFAULT)"
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"
	@make fclean -C $(LIBFT_PATH)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re
