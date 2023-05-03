# Config for the RISC-V QEMU Model
RAM_BASE_PHYSICAL  = 0x80000000
RAM_SIZE           = 0x4000000

# Toolchain Macros
TOOLCHAIN_PREFIX = riscv64-linux-gnu
CC = $(TOOLCHAIN_PREFIX)-gcc
LD = $(TOOLCHAIN_PREFIX)-ld
OBJCOPY = $(TOOLCHAIN_PREFIX)-objcopy


# Source and Build directories
SRC_DIR   = .
BUILD_DIR = build

# C compilation flags
CC_FLAGS = $(DEFINES) $(INCLUDES) -Wall -O$(OPTIMIZATION) -nostdlib
CC_FLAGS += -nostartfiles -ffreestanding -ggdb -c

# Assembler flags if any
ASM_FLAGS = -g

# Linker flags if any
LD_FLAGS =

# Defines to be passed to Linker
LD_MACROS = --defsym __RAM_BASE__=$(RAM_BASE_PHYSICAL) --defsym __RAM_SIZE__=$(RAM_SIZE)

# List of all source files
C_SRCS    = $(wildcard $(SRC_DIR)/*.c)
ASM_SRCS  = $(wildcard $(SRC_DIR)/*.S)
C_OBJS    = $(C_SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
ASM_OBJS  = $(ASM_SRCS:$(SRC_DIR)/%.S=$(BUILD_DIR)/%.o)


# Recipies

.PHONY: all clean make_build_directory run

all: make_build_directory tutorial_1.bin

tutorial_1.bin: tutorial_1.elf
	$(OBJCOPY) tutorial_1.elf -I binary tutorial_1.bin

tutorial_1.elf: $(ASM_OBJS) linker_script.ld $(C_OBJS)
	$(LD) -T linker_script.ld -o tutorial_1.elf $(ASM_OBJS) $(C_OBJS) $(LD_MACROS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.S
	$(CC) $(ASM_FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) tutorial_1.elf tutorial_1.bin

make_build_directory:
	mkdir -p $(BUILD_DIR)

run: all
	@echo "Use Ctrl+A X to exit Qemu"
	@qemu-system-riscv64 -M virt -nographic -bios none -kernel tutorial_1.elf
