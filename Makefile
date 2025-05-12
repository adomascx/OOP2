CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -O3 -std=c++17 -Iinclude -mconsole
CLASS_DIR = src

all: test_time test_class main

clean:
	del build\

main: $(CLASS_DIR)/OOP2.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o build/OOP2.exe $(CLASS_DIR)/OOP2.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)

test_time: $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o build/time_test.exe $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)

test_class: $(CLASS_DIR)/class_test.cpp $(CLASS_DIR)/include/catch_amalgamated.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o build/class_test.exe $(CLASS_DIR)/class_test.cpp $(CLASS_DIR)/include/catch_amalgamated.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
