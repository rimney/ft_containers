# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rimney <rimney@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 23:53:37 by rimney            #+#    #+#              #
#    Updated: 2023/01/18 02:55:50 by rimney           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VNAME = containers
MNAME = map
SNAME = stack
# V_SRCS = Vector/vector.hpp
MAIN_SRCS = main.cpp
FLAGS = -Wall -Wextra -Werror

all :
	@echo "Please Select One Of The Options"
	@echo "make vector"

vector :
	c++ $(FLAGS) $(V_SRCS) $(MAIN_SRCS) -o $(VNAME) -g

.PHONY : vector