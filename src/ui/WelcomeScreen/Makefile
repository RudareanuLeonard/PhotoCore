# Makefile for Qt6 Widgets project

# Compiler
CXX = g++

# Source files
SOURCES = WelcomeScreen.cpp

# Output executable
TARGET = WelcomeScreen

# Include directories
INCLUDES = -I./src

# Qt flags using pkg-config
QTFLAGS = $(shell pkg-config --cflags --libs Qt6Widgets)

# Build rule
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(SOURCES) $(INCLUDES) $(QTFLAGS) -std=gnu++17 -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)
