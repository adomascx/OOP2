CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17 -Os
CLASS_DIR = src
TEST_SOURCES = src/hello_test.cpp
TEST_EXECUTABLE = build/hello_test.exe

all: test_time test_class main

clean:
	del build\

main: $(CLASS_DIR)/OOP2.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o build/OOP2.exe $(CLASS_DIR)/OOP2.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)

test_time: $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o build/time_test.exe $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)

test_class: $(CLASS_DIR)/class_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o build/class_test.exe $(CLASS_DIR)/class_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
