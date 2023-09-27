NAME	= megaphone
	
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

GREEN		=	\e[92;5;118m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
RED 		= 	\033[1;31m
PURPLE 		= 	\033[1;35m
CYAN		=	\033[1;36m
CURSIVE		=	\e[33;3m
UMAG 		=	\e[4;35m
UCYN 		=	\e[4;36m

USAGE		=	printf "$(PURPLE) use $(CYAN)./megaphone [arg] $(RESET)$(PURPLE) to test this one.$(RESET)\n"

SRCS		=	megaphone.cpp

OBJ			=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "$(CURSIVE) $(GRAY) [Compiling] $(NAME) ..."
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJ) 
	@printf "done.\n$(RESET)"
	@printf "$(GREEN) \n\t CPP 00 ready.\n$(RESET)"
	@ $(USAGE)

.c.o :
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "$(CURSIVE) $(GRAY) [Removing] object form $(NAME) ...."
	@$(RM) $(NAME)
	@printf "done$(RESET)\n"

fclean: clean
	@printf "$(CURSIVE) $(GRAY) [Removing] executable form $(NAME) ...."
	@$(RM) $(NAME)
	@printf "done$(RESET)\n"

re: fclean all

.PHONY: all clean re