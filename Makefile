# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtessier <jtessier@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 11:50:56 by jtessier          #+#    #+#              #
#    Updated: 2023/04/07 15:07:37 by jtessier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= devis
CC			= gcc
FLAGS		= -Wall -Werror -Wextra

SRCS		=	main.c \
				informations.c \

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
	@$(CC) $(FLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
