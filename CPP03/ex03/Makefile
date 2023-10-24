DEFAULT_TARGET = diamondtrap
TARGET ?= $(DEFAULT_TARGET)

CXX = c++
CXXFLAGS = -std=c++98

SRC_DIR = src
OBJ_DIR = .obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

NUM_FILES = $(words $(SRC_FILES))
CUR_FILE = 0

USAGE		= @printf "$(CURSIVE)$(CYAN)\t[use $(PURPLE)./$(TARGET) $(CYAN) to start the program] \n"
GREEN		=	\033[92;5;118m
HGRN 		=	\033[1;92m
GRAY		=	\033[33;2;37m
RESET		=	\033[0m
PURPLE		= 	\033[4;35m
CYAN		=	\033[0;36m
CURSIVE		=	\033[33;3m

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)
	@printf "\n\tCompilation of $(TARGET)$(CURSIVE)$(GREEN) DONE\n$(RESET)"
	$(USAGE)
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(eval CUR_FILE := $(shell echo $$(($(CUR_FILE) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CUR_FILE) * 100 / $(NUM_FILES)))))
	@echo "$(CURSIVE)$(GRAY)[Compiling]$(RESET)$(GRAY) $< $(CURSIVE)[$(CUR_FILE)/$(NUM_FILES) files, $(PERCENT)%]$ \t$(RESET)✔\r"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@printf "$(CURSIVE)$(GRAY)- [Removing] $(TARGET) object ... $(RESET)"
	@rm -rf $(OBJ_DIR)
	@printf "$(CURSIVE)$(GREEN)\t   done\n$(RESET)"

fclean: clean
	@printf "$(CURSIVE)$(GRAY)- [Removing] $(TARGET) executable ... $(RESET)"
	@rm -f $(TARGET)
	@printf "$(CURSIVE)$(GREEN)\t done\n$(RESET)\n"

re: fclean all
.PHONY: all clean re
