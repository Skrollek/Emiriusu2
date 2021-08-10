CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall `pkg-config --cflags glfw3`

ENGINE_OBJ = engine/engine.o
OBJ = src/main.o
GLFW = `pkg-config --static --libs glfw3` -lopengl32

INC_DIR=.
SRC_DIR=./src
ENGINE_DIR=./engine

#PCH_SRC = src/pch.hpp
#PCH_HEADERS = 
#PCH_OUT = src/pch.hpp.gch

NAME = EmiriusuGL

all: $(ENGINE_OBJ) $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) $(ENGINE_OBJ) -o $(NAME) $(GLFW)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c -I$(INC_DIR) $< -o $@

$(ENGINE_DIR)/%.o: $(ENGINE_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c -I$(INC_DIR) $< -o $@
clean:
	@rm -f $(NAME) $(OBJ) $(ENGINE_OBJ)



