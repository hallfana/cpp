NAME=phonebook

CPP=g++-9
CPP_FLAGS=-std=c++98 -Wall -Wextra -Werror

SRC = ./phonebook.cpp

$(NAME):
	$(CPP) $(CPP_FLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	@true

clean:
	@true

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re