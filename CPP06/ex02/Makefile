DEFAULT_TARGET = bureaucraft
TARGET ?= $(DEFAULT_TARGET)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
OBJ_DIR = .obj
INCLUDE_DIR = include
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
HDR_FILES = $(wildcard $(INCLUDE_DIR)/*.hpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

NUM_FILES = $(words $(SRC_FILES))
CUR_FILE = 0

USAGE		= @printf "$(CURSIVE)$(CYAN)	[use $(PURPLE)./$(TARGET) $(CYAN) to start the program] 
"
GREEN		=	[92;5;118m
HGRN 		=	[1;92m
GRAY		=	[33;2;37m
RESET		=	[0m
PURPLE		= 	[4;35m
CYAN		=	[0;36m
CURSIVE		=	[33;3m

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)
	@printf "
	Compilation of $(TARGET)$(CURSIVE)$(GREEN) DONE
$(RESET)"
	@echo "Compiler flags used: $(CXXFLAGS)"
	$(USAGE)
	

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HDR_FILES)
	@mkdir -p $(@D)
	@$(eval CUR_FILE := $(shell echo $$(($(CUR_FILE) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CUR_FILE) * 100 / $(NUM_FILES)))))
	@echo "$(CURSIVE)$(GRAY)[Compiling]$(RESET)$(GRAY) $< $(CURSIVE)[$(CUR_FILE)/$(NUM_FILES) files, $(PERCENT)%]$ 	$(RESET)✔"
	@$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@printf "$(CURSIVE)$(GRAY)- [Removing] $(TARGET) object ... $(RESET)"
	@rm -rf $(OBJ_DIR)
	@printf "$(CURSIVE)$(GREEN)	   done
$(RESET)"

fclean: clean
	@printf "$(CURSIVE)$(GRAY)- [Removing] $(TARGET) executable ... $(RESET)"
	@rm -f $(TARGET)
	@printf "$(CURSIVE)$(GREEN)	 done
$(RESET)
"

re : fclean all

.PHONY: all clean re

