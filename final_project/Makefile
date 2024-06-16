# Compiler
CC = gcc

# Directories
SRCDIR = game
OBJDIR = obj
BINDIR = bin

# Files
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/SDL_function.c
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)/interactive_novel_engine

# Flags
CFLAGS = -g -I$(SRCDIR)
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Default target
all: $(EXECUTABLE)

# Link object files to create the executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
