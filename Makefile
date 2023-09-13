# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 11:09:56 by ricardovala       #+#    #+#              #
#    Updated: 2023/08/08 11:09:57 by ricardovala      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	./srcs/pipex.c \
		./srcs/errmsg.c

LIBFT_DIR = ./srcs/libft/
LIBFT = $(LIBFT_DIR)/libft.a


OBJS :=$(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)  

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./srcs/libft --no-print-directory --silent

tester: $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

clean_library:
	@$(MAKE) -C ./srcs/libft fclean --no-print-directory --silent

clean:
	@rm -f $(OBJS)

fclean: clean clean_library
	@rm -f $(NAME)
	@rm -f checker

re: fclean all

.PHONY: all tester bonus clean fclean runner re