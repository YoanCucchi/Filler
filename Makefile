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

FLAGS = -Wall #-Werror -Wextra
INCLUDES = -I ./includes/

### PATH ###
SRCS_PATH = srcs/
OBJ_DIR  = objects/
LIBFT_PATH = libft/
LIB_LFT	=	-L ./libft/ -lft

SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

DEFAULT = \033[0;39m
GRAY = \033[0;90m
GREEN = \033[0;92m
CYAN = \033[0;96m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDES) $(LIB_LFT)
	@echo "$(GREEN)Player ready!$(DEFAULT)"

$(OBJ_DIR)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN)Compilation of $(notdir $<) done!$(DEFAULT)"

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
