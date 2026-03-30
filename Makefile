# Makefile for Qt6 Widgets project

# Compiler
CXX = g++
MOC = /usr/lib/qt6/moc

# Qt flags using pkg-config
QTFLAGS = $(shell pkg-config --cflags --libs Qt6Widgets)

# Source files
SOURCES = src/main.cpp \
          src/ui/WelcomeScreen/WelcomeScreen.cpp \
          src/ui/MainScreen/MainScreen.cpp

# Headers that contain Q_OBJECT
MOC_HEADERS = src/ui/WelcomeScreen/WelcomeScreen.h \
              src/ui/MainScreen/MainScreen.h

# Build directory for generated files
BUILDDIR = build

# Generated moc .cpp files (flat, all in build/)
MOC_SOURCES = $(addprefix $(BUILDDIR)/moc_, $(notdir $(MOC_HEADERS:.h=.cpp)))

# Object files
OBJECTS     = $(SOURCES:%.cpp=$(BUILDDIR)/%.o)
MOC_OBJECTS = $(MOC_SOURCES:.cpp=.o)

# Output executable
TARGET = main

# Include directories
INCLUDES = -I./src \
           -I./src/ui/WelcomeScreen \
           -I./src/ui/MainScreen \
           -I./src/ui/Screen

# Compiler flags
CXXFLAGS = $(INCLUDES) $(QTFLAGS) -std=gnu++17 -fPIC

# ── Build rules ──────────────────────────────────────────────────────────────

all: $(TARGET)

# Link everything
$(TARGET): $(OBJECTS) $(MOC_OBJECTS)
	$(CXX) $^ $(QTFLAGS) -o $@

# Compile real sources into build/src/...
$(BUILDDIR)/%.o: %.cpp | $(BUILDDIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generate moc files: build/moc_Foo.cpp from src/.../Foo.h
$(BUILDDIR)/moc_%.cpp: src/ui/WelcomeScreen/%.h | $(BUILDDIR)
	$(MOC) $< -o $@

$(BUILDDIR)/moc_%.cpp: src/ui/MainScreen/%.h | $(BUILDDIR)
	$(MOC) $< -o $@

# Compile generated moc files
$(BUILDDIR)/moc_%.o: $(BUILDDIR)/moc_%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build dir
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Clean
clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all clean
