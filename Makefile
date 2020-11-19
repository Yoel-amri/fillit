# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakfas <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 14:18:24 by aakfas            #+#    #+#              #
#    Updated: 2018/11/16 20:14:17 by yel-amri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = read.c solve.c map.c main.c valid.c help.c

SRCO = *o

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC) libft/*c
	gcc	$(FLAG) $(SRCO) -o $(NAME)

clean :
	rm -f $(SRCO)

fclean :
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all
