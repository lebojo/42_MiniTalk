# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 17:33:03 by jchapell          #+#    #+#              #
#    Updated: 2023/01/17 18:57:42 by jchapell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------  COLORS  ------------------------------------------------------ #
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m

CLIENT		= client
SERVER		= server

SRC_PATH	= ./

# ------------  FLAGS  ------------------------------------------------------- #
CFLAGS 		= -Wall -Wextra -Werror
CC			= @cc
RM			=	rm -rf

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC 		= 	client.c						\
				server.c						\
				utils.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS 		= $(addprefix $(SRC_PATH),$(SRC))
OBJS		= ${SRCS:.c=.o}

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
			@echo "$(COLOUR_CYAN)Compile serveur"
			$(CC) $(CFLAGS) -o $@ server.o utils.o
			@echo "$(COLOUR_RED)Serveur ready."

$(CLIENT): $(OBJS)
			@echo "$(COLOUR_CYAN)Compile client"
			$(CC) $(CFLAGS) -o $@ client.o utils.o
			@echo "$(COLOUR_ORANGE)Client ready."

%.o: %.c
		${CC} $(CFLAGS) -c $< -o $@ -g3

clean:
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(CLIENT) $(SERVER) *.a

re:			fclean all

.PHONY: re ignore fclean clean all $(NAME)