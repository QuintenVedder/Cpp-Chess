# Compiler
CXX = g++
CXX_WIN = x86_64-w64-mingw32-g++

# Compiler flags
CXXFLAGS = -std=c++17

# Paths to SFML headers and libraries for cross-compilation
### SFML_WIN_PATH = # Path/to/sfml/files/for/windows
### SFML_WIN_INCLUDE = $(SFML_WIN_PATH)/include
### SFML_WIN_LIB = $(SFML_WIN_PATH)/lib

# SFML Libraries
SFML_LIBS_LINUX = -lsfml-graphics -lsfml-system -lsfml-window
# SFML_LIBS_WIN = -lsfml-graphics -lsfml-system -lsfml-window -lwinmm -lgdi32

# Source files
SRCS = main.cpp

# Target executables
TARGET_LINUX = chess-executable
### TARGET_WIN = chess-executable.exe

# Default target
all: $(TARGET_LINUX) ### $(TARGET_WIN)

# Rule to build the Linux target executable
$(TARGET_LINUX): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_LINUX) $(SRCS) $(SFML_LIBS_LINUX)

# Rule to build the Windows target executable
### $(TARGET_WIN): $(SRCS)
### 	$(CXX_WIN) $(CXXFLAGS) -I$(SFML_WIN_INCLUDE) -L$(SFML_WIN_LIB) -o $(TARGET_WIN) $(SRCS) $(SFML_LIBS_WIN)

# Rule to run the Linux executable
run: $(TARGET_LINUX)
	./$(TARGET_LINUX)

# Clean up build files
clean:
	rm -f $(TARGET_LINUX) 
### 	rm -f $(TARGET_WIN)

# Rule to clean->build->run for Linux
cbr: clean all run

# Prevent make from interpreting file names as targets
.PHONY: all run clean cbr
