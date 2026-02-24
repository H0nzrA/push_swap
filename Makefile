# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trakotoz <trakotoz@student.42antananarivo  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 09:04:21 by trakotoz          #+#    #+#              #
#    Updated: 2026/02/24 12:00:55 by tiana-an         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

C_RESET		= \033[0m
C_GREEN		= \033[032m
C_BLUE		= \033[034m
C_MAGNETA	= \033[035m

DIR_LIB			= ft_printf
LIBFTPRINTF		= $(DIR_LIB)/libftprint.a

MANDATORY = main push_swap managements \
			parsing utils take_command \
			command_push_swap command_rotate command_reverse \
			compute_disorder \
			adaptive_sort minmax_sort \
			chunk_based_sort chunk_b_s_utils radix_lsd_sort \
			benchmark benchmark_utils

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

RM = rm -rf

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(MANDATORY)))

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(DIR_LIB) -lftprintf -o $(NAME) 
	@echo "${C_GREEN}Build Push_swap${C_RESET}"

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(LIBFTPRINTF):
	$(MAKE) -C $(DIR_LIB)

clean :
	@$(MAKE) clean -sC $(DIR_LIB)
	@$(RM) $(OBJ_DIR)
	@echo "${C_BLUE}Clean objects files${C_RESET}"

fclean : clean
	@$(MAKE) fclean -sC $(DIR_LIB)
	@$(RM) $(NAME)
	@echo "${C_MAGNETA}Clean all generated files${C_RESET}"

re : fclean all

.PHONY : all clean fclean re
