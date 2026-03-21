# Makefile for Qt6 Widgets project

# Compiler
CXX = g++

# Source files
SOURCES = src/main.cpp src/ui/WelcomeScreen/WelcomeScreen.cpp src/ui/MainScreen/MainScreen.cpp

# Output executable
TARGET = main

# Include directories
INCLUDES = -I./src -I./src/ui/WelcomeScreen -I./src/ui/MainScreen -I./src/ui/Screen

# Qt flags using pkg-config
QTFLAGS = $(shell pkg-config --cflags --libs Qt6Widgets)

# Build rule
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(INCLUDES) $(QTFLAGS) -std=gnu++17 -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
