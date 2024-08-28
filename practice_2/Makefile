ALG_DIR=src/algorithms/

BUILD_DIR=build

CC=gcc

default: all

all: 
	$(CC) -o $(BUILD_DIR)/hash $(ALG_DIR)/hash.c src/utils.c
	$(CC) -o $(BUILD_DIR)/btree $(ALG_DIR)/btree.c src/utils.c
	$(CC) -o $(BUILD_DIR)/bst $(ALG_DIR)/bst.c src/utils.c

clean:
	rm -rf $(BUILD_DIR)/*.o

test:
	./build/hash
	./build/bst
	./build/btree
