ALG_DIR=src/algorithms/
INPUT_DIR=src/input/

SRC_FILES=src/main.c $(INPUT_DIR)input.c src/utils.c

BUILD_DIR=build

CC=gcc

CC_FLAGS=	-W \
			-Wall \

# Flags de otimização específicas para os arquivos em ALG_DIR
OPT_FLAGS=	-O2 \
			-march=native

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(ALG_DIR)%.c | $(BUILD_DIR)
	$(CC) $(OPT_FLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: src/main.c | $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(BUILD_DIR)/input.o: $(INPUT_DIR)input.c | $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

$(BUILD_DIR)/utils.o: src/utils.c | $(BUILD_DIR)
	$(CC) $(CC_FLAGS) -c $< -o $@

default: all

all: $(BUILD_DIR)/main.o $(BUILD_DIR)/*.o
	$(CC) -o $(BUILD_DIR)/main $^

clean:
	rm -rf $(BUILD_DIR)/*.o
