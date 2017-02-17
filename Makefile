# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebs <wdebs@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 23:19:31 by wdebs             #+#    #+#              #
#    Updated: 2017/02/16 23:37:09 by wdebs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serv
SRC = h_server/h_server.c

OBJ = h_server/h_server.o

IFLAGS = -I includes
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
