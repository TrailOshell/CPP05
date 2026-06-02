# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 18:22:49 by tsomchan          #+#    #+#              #
#    Updated: 2026/06/02 17:23:49 by tsomchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C++ 		= c++
C++FLAGS	= -std=c++98 -Wall -Wextra -std=c++98

NAME 	=	bureaucrat

INC		=	.
INCS	=	Bureaucrat.hpp \
			Form.hpp

SRCS	=	main.cpp \
			Bureaucrat.cpp \
			Form.cpp

OBJS_PTH	= objs/
OBJS		= $(SRCS:%.cpp=$(OBJS_PTH)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(C++FLAGS) $(OBJS) -I$(INC) -o $(NAME)

$(OBJS_PTH)%.o: %.cpp Makefile $(INCS) | $(OBJS_PTH)
	$(C++) $(C++FLAGS) -c $< -o $@
$(OBJS_PTH):
	mkdir -p $(OBJS_PTH)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_PTH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# More

r: run

run: all
	./$(NAME)

VFLAGS		=	--leak-check=full --show-leak-kinds=all

val: $(NAME)
	valgrind $(VFLAGS) ./$(NAME)

.PHONY: r run val