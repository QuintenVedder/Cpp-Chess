# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17

# SFML Libraries
SFML_LIBS = -lsfml-graphics -lsfml-system -lsfml-window

# Source files
SRCS = main.cpp

# Detect OS and set variables accordingly
ifeq ($(OS),Windows_NT)
    TARGET = chess-executable.exe
    RM = del
else
    TARGET = chess-executable
    RM = rm -f
endif

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(SFML_LIBS)

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

# Rule to clean->build->run
cbr:
	rm -f $(TARGET)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(SFML_LIBS)
	./$(TARGET)
