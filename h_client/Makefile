# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 23:19:31 by wdebs             #+#    #+#              #
#    Updated: 2017/02/16 23:36:00 by wdebs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clnt
SRC = h_client.c

OBJ = h_client.o

IFLAGS = -I ../includes
FLAGS = -Wall -Wextra -Werror

CC = gcc $(FLAGS)
RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -o $@ $^

clean:
	@$(RM) -r $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
