# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduplain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 18:12:13 by dburgun           #+#    #+#              #
#    Updated: 2020/09/27 23:07:20 by lduplain         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

-include sources.mk

NAME = rush-02

OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror -O3 -I includes

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

all: $(NAME)

re: fclean all

norminette:
	norminette sources includes

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

gmk:
	./scripts/generate-mk.sh

.PHONY: all clean fclean re gmk norminette
