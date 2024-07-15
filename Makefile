# Compiler and linker
CC = gcc

# Directories
INCDIR = headers
SRCDIR = sources
BINDIR = bin

# Compiler flags
CFLAGS = `pkg-config --cflags glib-2.0` -I$(INCDIR) -Wall

# Linker flags
LDFLAGS = `pkg-config --libs glib-2.0`

# Source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BINDIR)/%.o)

# Executable name
TARGET = my_program

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Rule to build the object files
$(BINDIR)/%.o: $(SRCDIR)/%.c | $(BINDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the bin directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(BINDIR)

# Phony targets
.PHONY: all clean
