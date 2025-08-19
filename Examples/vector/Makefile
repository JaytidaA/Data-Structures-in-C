# GNU Makefile for compiling Vector Examples
# Written by JaytidaA

CC=gcc
CFLAGS=-O -W -Wall -pedantic -ansi -std=c99

BUILD_DIR=build
BIN_DIR=bin
PROJ_DIR=../..
INC_DIR=$(PROJ_DIR)/include

.PHONY: clean clean_all

$(BUILD_DIR)/general: $(BIN_DIR)/general.o $(BIN_DIR)/vector.o $(BIN_DIR)/vector_utils.o | $(BUILD_DIR)
	@echo "Run 'make clean' or 'make clean_all' to clean up leftovers"
	$(CC) -o $@ $^

$(BUILD_DIR)/maximum_sum: $(BIN_DIR)/maximum_sum.o $(BIN_DIR)/vector.o $(BIN_DIR)/vector_utils.o | $(BUILD_DIR)
	@echo "Run 'make clean' or 'make clean_all' to clean up leftovers"
	$(CC) -o $@ $^

$(BIN_DIR)/general.o: general.c $(INC_DIR)/vector/vector.h $(INC_DIR)/vector/vector_utils.h | $(BIN_DIR)
	$(CC) -o $@ -c $< -I $(INC_DIR)

$(BIN_DIR)/maximum_sum.o: maximum_sum.c $(INC_DIR)/vector/vector.h $(INC_DIR)/vector/vector_utils.h | $(BIN_DIR)
	$(CC) -o $@ -c $< -I $(INC_DIR)

$(BIN_DIR)/vector.o: $(PROJ_DIR)/vector/vector.c $(INC_DIR)/vector/vector.h $(INC_DIR)/err_handle.h | $(BIN_DIR)
	$(CC) -o $@ -c $< -I $(INC_DIR)

$(BIN_DIR)/vector_utils.o: $(PROJ_DIR)/utils/vector_utils.c $(INC_DIR)/vector/vector_utils.h $(INC_DIR)/vector/vector.h $(INC_DIR)/utils.h | $(BIN_DIR)
	$(CC) -o $@ -c $< -I $(INC_DIR)

$(BUILD_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -r $(BIN_DIR)/*

clean_all:
	rm -r $(BIN_DIR)
	rm -r $(BUILD_DIR)
