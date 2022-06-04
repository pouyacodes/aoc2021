.PHONY: clean run

BUILD_DIR := .
APP_NAME := solve
TARGET := $(BUILD_DIR)/$(APP_NAME)
INPUT_FILE := input
CPP_FILES := solve.cpp
OBJ_FILES := $(CPP_FILES:%.cpp=%.o)
CXX_FLAGS := 

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $^ -o $@ $(CXX_FLAGS)

%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXX_FLAGS)

clean:
	rm -rf $(OBJ_FILES)
	rm -rf $(TARGET)

run: $(TARGET) $(INPUT_FILE)
	@$(TARGET) < $(INPUT_FILE)
