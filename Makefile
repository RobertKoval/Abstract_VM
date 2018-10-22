NAME = avm

SRC = AbstractVMFactory.cpp\
      AbstractVM.cpp\
      main.cpp\
      ../gen/avmLexer.cpp\
       ../gen/avmParser.cpp \
       ../gen/avmVisitor.cpp\
       ../gen/avmListener.cpp\
       ../gen/avmBaseVisitor.cpp\
       ../gen/avmBaseListener.cpp\

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

CXX = clang++
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIB_INC_DIR = gen
CXXFLAGS =  -std=c++14 -Wall -Werror -Wextra  -I. -I ./antlr4-runtime/ -I ./lib/ \
												-I ./gen/ -I ./includes/
LINKER =  -L lib/ -lantlr4-runtime

# COLORS
RESET=		\033[0m
RED=		\033[31m
GREEN=		\033[32m
YELLOW=		\033[33m
BLUE=		\033[34m
MAGENTA=	\033[35m
CYAN=		\033[36m
WHITE=		\033[37m
BOLDRED=	\033[1m\033[31m
BOLDWHITE=	\033[1m\033[37m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INC_DIR) $(LIB_INC_DIR)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(LINKER) $(OBJ)
	@echo "$(GREEN)avm  $(BOLDRED)made$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p obj
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf gen/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all