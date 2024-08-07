# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 19:18:10 by aneekhra          #+#    #+#              #
#    Updated: 2024/07/24 15:21:29 by aneekhra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

FLAGS = -g -pthread -Wall -Wextra -Werror

SRCS = check.c clean.c init.c main.c monitoring.c routine.c threads.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, re, clean, fclean