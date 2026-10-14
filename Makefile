# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 15:30:28 by tsomchan          #+#    #+#              #
#    Updated: 2026/10/14 16:46:01 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

all: 0 1 2 3

0: 00
00:
	make -C ex00/
	ex00/bureaucrat

1: 01
01: 
	make -C ex01/
	ex01/bureaucrat

2: 02
02:
	make -C ex02/
	ex02/bureaucrat

3: 03
03:
	make -C ex03/
	ex03/bureaucrat
