# GNU Makefile for compiling Stack Examples

CC=gcc
CFLAGS=-O -W -Wall -pedantic -ansi -std=c99

BUILD_DIR=build
BIN_DIR=bin
PROJ_DIR=../..
INC_DIR=$(PROJ_DIR)/include

.PHONY: clean clean_all

$(BUILD_DIR)/general: $(BIN_DIR)/general.o $(BIN_DIR)/stack.o | $(BUILD_DIR)
	@echo "Run 'make clean' or 'make clean_all' to clean up leftovers"
	$(CC) -o $@ $^

$(BIN_DIR)/general.o: general.c $(INC_DIR)/stack/stack.h | $(BIN_DIR)
	$(CC) -o $@ -c $< -I $(INC_DIR)

$(BIN_DIR)/stack.o: $(PROJ_DIR)/stack/stack.c $(INC_DIR)/stack/stack.h $(INC_DIR)/err_handle.h | $(BIN_DIR)
	$(CC) -o $@ -c $< -I $(INC_DIR)

$(BUILD_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(BIN_DIR)/*

clean_all:
	rm -rf $(BIN_DIR)
	rm -rf $(BUILD_DIR)