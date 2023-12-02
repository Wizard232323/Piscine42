# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkubina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 19:42:33 by gkubina           #+#    #+#              #
#    Updated: 2023/07/25 20:27:34 by gkubina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
EXEC = bsq
F_DIR = src
H_DIR = library
SRC = $(F_DIR)/main.c $(F_DIR)/algo_bsq.c $(F_DIR)/alloc_free.c $(F_DIR)/an_firstline.c\
                $(F_DIR)/filecheck.c $(F_DIR)/helpers.c $(F_DIR)/indiv_checks.c $(F_DIR)/manage_file.c
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(FLAGS) -I $(H_DIR) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -I $(H_DIR) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(EXEC)

re : fclean all

