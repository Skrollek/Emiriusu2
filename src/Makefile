CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall `pkg-config --cflags glfw3`

OBJ = $(SRC_DIR)/main.o
GLFW = `pkg-config --static --libs glfw3` -lopengl32

INC_DIR=.
SRC_DIR=./src

NAME = app

all: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) $(GLFW) -L ./ -lemiriusugl

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -I$(INC_DIR) $< -o $@

clean:
	rm -f $(NAME) $(OBJ)
