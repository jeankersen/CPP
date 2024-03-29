NAME = phonebook

SRC = main.cpp PhoneBookClass.cpp PhoneBookUtils.cpp PhoneBookMenu.cpp
OBJ_DIR = ./obj
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))
INCLUDES = PhoneBookClass.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow -Wshadow -Wno-sign-conversion -Wno-unused-parameter

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@if [ ! -d "$(OBJ_DIR)" ] ; then \
		mkdir $(OBJ_DIR); \
	fi; 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ] ; then \
		echo "rm -r $(OBJ_DIR)"; \
		rm -r $(OBJ_DIR); \
	fi; \

fclean: clean
	rm -f ./$(NAME)

re: fclean all

.PHONY: clean fclean re
