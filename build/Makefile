CXX = g++
CXXFLAGS = -I include -std=c++17 -Wall
SRC = src/main.cpp src/Task.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = build/planner

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
