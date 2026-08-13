# Compiler and Flags
CC        := gcc
CFLAGS    := -Wall -Wextra -Werror -std=c11 -Iinclude -MMD -MP
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build

# Detect OS using $(OS) (Windows sets this) or uname (Unix-like)
ifeq ($(OS),Windows_NT)
    # Windows-specific configuration
    EXE         := .exe
    TARGET      := $(BUILD_DIR)/main$(EXE)
    MKDIR_BUILD := if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
    MKDIR_SRC   := if not exist "$(BUILD_DIR)\$(SRC_DIR)" mkdir "$(BUILD_DIR)\$(SRC_DIR)"
    RM          := if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
    RUN_CMD     := $(BUILD_DIR)\main.exe
    # Use forward slashes for object file paths on Windows
    OBJS_PATH   := $(subst /,\,$(OBJS))
else
    # Linux/macOS-specific configuration
    EXE         :=
    TARGET      := $(BUILD_DIR)/main
    MKDIR_BUILD := mkdir -p $(BUILD_DIR)
    MKDIR_SRC   := mkdir -p $(BUILD_DIR)/$(SRC_DIR)
    RM          := rm -rf $(BUILD_DIR)
    RUN_CMD     := ./$(TARGET)
    OBJS_PATH   := $(OBJS)
endif

# Source & Object Files
SRCS      := main.c $(wildcard $(SRC_DIR)/*.c)
OBJS      := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS      := $(OBJS:.o=.d)

.PHONY: all clean run test help

# Default target
all: clean $(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  make all      - Clean and build the project"
	@echo "  make clean    - Remove build directory"
	@echo "  make run      - Build and run the executable"
	@echo "  make test     - Build and run tests (alias for run)"
	@echo "  make help     - Display this help message"

# Link step - combine all object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo Build successful: $@

# Compile root main.c
$(BUILD_DIR)/main.o: main.c
	@$(MKDIR_BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile src/*.c files
$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Include auto-generated dependency rules
-include $(DEPS)

# Run target
run: $(TARGET)
	@echo --- Running Target ---
	@$(RUN_CMD)

# Test target (alias for run)
test: run

# Delete build folder
clean:
ifeq ($(OS),Windows_NT)
	@if exist "$(BUILD_DIR)" (rmdir /s /q "$(BUILD_DIR)" >nul 2>&1) || true
else
	@rm -rf $(BUILD_DIR)
endif
	@echo Build directory cleaned
