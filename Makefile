CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall `pkg-config --cflags glfw3`

OBJ = main.o
GLFW = `pkg-config --static --libs glfw3` -lopengl32

INC_DIR=.
SRC_DIR=./src

PCH_SRC = src/pch.hpp
#PCH_HEADERS = 
PCH_OUT = src/pch.hpp.gch

NAME = EmiriusuGL

all: $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(GLFW)
%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c -I$(INC_DIR) $< -o $@
clean:
	@rm -f $(NAME) $(OBJ)



