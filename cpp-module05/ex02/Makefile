NAME		=	form

HEADER		=	./include/

CC			=	c++

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER)  -std=c++98 -Wno-unused-parameter -Wshadow

SRC_DIR		=	srcs/
OBJ_DIR		=	obj/

SRCS		=	$(addprefix $(SRC_DIR), main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp)
OBJS		=	$(addprefix $(OBJ_DIR), $(notdir $(SRCS:.cpp=.o)))

all			:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR)	:
				mkdir -p $(OBJ_DIR)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -rf $(OBJ_DIR)

fclean		:	clean
				rm -rf $(NAME) *_shrubbery

re			:	fclean all


