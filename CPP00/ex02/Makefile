NAME			= jod

CC				= c++

CPPFLAGS		= -Wall -Wextra -Werror -std=c++98

OBJDIR	= obj/
OBJFILE = $(SRCFILE:.cpp=.o)
OBJS	= $(addprefix $(OBJDIR), $(OBJFILE))
#OBJ			=	$(SRCFILE:.cpp=.o)
#SRCDIR	= src/
#SRCS	= $(addprefix $(SRCDIR), $(SRCFILE))

SRCFILE	=	Account.cpp \
			tests.cpp \


GREEN		=	\e[92;5;118m
HGRN 		=	\e[1;92m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
PURPLE		= 	\e[4;35m
CYAN		=	\e[0;36m
CURSIVE		=	\e[33;3m

USAGE		= @printf "$(CURSIVE)$(CYAN) use $(PURPLE)./$(NAME) $(CYAN) to start the program \n"
#--------------------------------------------------------------------------#


$(NAME) : $(OBJFILE)
	@printf "$(CURSIVE)$(GRAY) 	- [Compiling] $(NAME) object ... $(RESET)"
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJFILE)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"
	@$(USAGE)


.cpp.o :
	@ $(CC) $(CPPFLAGS) -c $< -o $@

all:  $(NAME)

clean:
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] $(NAME) object ... $(RESET)"
	@rm -f $(OBJFILE)
	@printf "$(CURSIVE)$(GREEN)\t\t done\n$(RESET)"

fclean: clean
	@printf "$(CURSIVE)$(GRAY) 	- [Removing] $(NAME) executable ... $(RESET)"
	@rm -f $(NAME)
	@printf "$(CURSIVE)$(GREEN)\t done\n$(RESET)\n"


re: fclean all


.PHONY:	all clean fclean re
