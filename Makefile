# This file contains a make script for the OminousOverflow application
#
# Author: Josh McIntyre
#

# This block defines makefile variables
UI_FILES=src/ui/*.c
CORE_FILES=src/core/*.c
TEST_FILES=tests/*.c
INCLUDE_CORE=src/core
INCLUDE_UI=src/ui
INCLUDE_TESTS=tests/

BUILD_DIR=bin
BUILD_BIN=ominousoverflow
BUILD_TEST_BIN=test_ominousoverflow

CC=gcc
FLAGS=-Werror -I$(INCLUDE_CORE) -I$(INCLUDE_UI) -I$(INCLUDE_TESTS)

# This rule builds the utility
build: $(CORE_FILES) $(UI_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -o $(BUILD_DIR)/$(BUILD_BIN) $(CORE_FILES) $(UI_FILES)

# This rule builds the unit tests
tests: $(TEST_FILES) $(CORE_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -o $(BUILD_DIR)/$(BUILD_TEST_BIN) $(TEST_FILES) $(CORE_FILES)

# This rule cleans the build directory
clean: $(BUILD_DIR)
	rm $(BUILD_DIR)/* 
	rmdir $(BUILD_DIR)
