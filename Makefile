# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 19:35:37 by oboutarf          #+#    #+#              #
#    Updated: 2022/12/13 10:51:29 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME          				= 	pipex

SRCS           				=	main/main.c src/error.c

FIND_INCLD					=	-Iincld

CC                   		=	gcc -g3 -Wall -Wextra -Werror

OBJ                 		= 	$(SRCS:.c=.o)

RM                   		= 	rm -rf


all:        $(NAME)

%.o: %.c
			$(CC) $(FIND_INCLD) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)


clean:
			$(RM) $(OBJ)

fclean:     clean
			$(RM) $(NAME) 

re:         fclean $(NAME)
