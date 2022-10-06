# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 21:13:45 by ycucchi           #+#    #+#              #
#    Updated: 2022/04/12 15:35:38 by ycucchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
ft_toupper.c ft_long_itoa.c ft_unsigned_long_itoa.c ft_nbrlen.c \
ft_print_char.c ft_putnstr.c ft_octal_itoa.c get_next_line.c\
./ft_printf/ft_printf.c ./ft_printf/ft_print_utils.c ./ft_printf/ft_parse.c \
./ft_printf/ft_initialize_parameter.c ./ft_printf/ft_print_str.c \
./ft_printf/ft_print_nbr.c ./ft_printf/ft_print_hex.c \
./ft_printf/ft_length_flags.c ./ft_printf/ft_print_flag_hex.c \
./ft_printf/ft_print_octal.c ./ft_printf/ft_octal_helper.c \
./ft_printf/ft_hex_helper.c ./ft_printf/ft_print_unbr.c \
./ft_printf/ft_nbr_helper.c ./ft_printf/ft_print_float.c \
./ft_printf/ft_float_helper.c ./ft_printf/ft_initialize_float.c \
./ft_printf/ft_float_rounding.c ./ft_printf/ft_float_helper_print.c \
./ft_sqrt.c ./ft_pow.c

OBJECTS = $(SOURCES:%.c=$(DIR_OBJ)%.o)

DIR_OBJ = ./objects/
DIR_SRC = ./srcs/

# Colors
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
PURPLE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(PURPLE)Creating libft..$(DEFAULT)"
	@ar rcs $(NAME) $(OBJECTS)
	@echo "$(GREEN)libft created!$(DEFAULT)"

$(DIR_OBJ)%.o:$(DIR_SRC)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(PURPLE)Cleaning all objects..$(DEFAULT)"
	@rm -rf $(DIR_OBJ)
	@echo "$(GRAY)$(OBJECTS) cleaned!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GRAY)$(NAME) cleaned!$(DEFAULT)"

re: fclean all
