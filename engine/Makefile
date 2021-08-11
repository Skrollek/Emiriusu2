CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall `pkg-config --cflags glfw3`

ENGINE_OBJ = $(ENGINE_DIR)/engine.o
GLFW = `pkg-config --static --libs glfw3` -lopengl32

INC_DIR=.
ENGINE_DIR=./engine

NAME = emiriusugl.dll

all: $(ENGINE_OBJ)
	$(CXX) $(CXXFLAGS) -shared -o $(NAME) $(ENGINE_OBJ) $(GLFW)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -I$(INC_DIR) $< -o $@

clean:
	rm -f $(NAME) $(ENGINE_OBJ)
