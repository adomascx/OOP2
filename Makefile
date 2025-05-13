CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17 -Os
VECTOR_DIR = konteineriai/vector
DEQUE_DIR = konteineriai/deque
LIST_DIR = konteineriai/list
CLASS_DIR = class

all: test main

# test: test_d test_l test_v test_time test_class

test: test_class test_time

build: build_d build_l build_v main

clean:
	del build\

# build_d: $(DEQUE_DIR)/OOP1.cpp $(wildcard $(DEQUE_DIR)/lib/*.cpp)
# 	$(CXX) $(CXXFLAGS) -o build/OOP1_D.exe $(DEQUE_DIR)/OOP1.cpp $(wildcard $(DEQUE_DIR)/lib/*.cpp)

# test_d: $(DEQUE_DIR)/time_test.cpp $(wildcard $(DEQUE_DIR)/lib/*.cpp)
# 	$(CXX) $(CXXFLAGS) -o build/time_test_D.exe $(DEQUE_DIR)/time_test.cpp $(wildcard $(DEQUE_DIR)/lib/*.cpp)

# build_l: $(LIST_DIR)/OOP1.cpp $(wildcard $(LIST_DIR)/lib/*.cpp)
# 	$(CXX) $(CXXFLAGS) -o build/OOP1_L.exe $(LIST_DIR)/OOP1.cpp $(wildcard $(LIST_DIR)/lib/*.cpp)

# test_l: $(LIST_DIR)/time_test.cpp $(wildcard $(LIST_DIR)/lib/*.cpp)
# 	$(CXX) $(CXXFLAGS) -o build/time_test_L.exe $(LIST_DIR)/time_test.cpp $(wildcard $(LIST_DIR)/lib/*.cpp)

# build_v: $(VECTOR_DIR)/OOP1.cpp $(wildcard $(VECTOR_DIR)/lib/*.cpp)
# 	$(CXX) $(CXXFLAGS) -o build/OOP1_V.exe $(VECTOR_DIR)/OOP1.cpp $(wildcard $(VECTOR_DIR)/lib/*.cpp)

# test_v: $(VECTOR_DIR)/time_test.cpp $(wildcard $(VECTOR_DIR)/lib/*.cpp)
# 	$(CXX) $(CXXFLAGS) -o build/time_test_V.exe $(VECTOR_DIR)/time_test.cpp $(wildcard $(VECTOR_DIR)/lib/*.cpp)

main: $(CLASS_DIR)/OOP2.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP2.exe $(CLASS_DIR)/OOP2.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)

test_time: $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/time_test.exe $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)

test_class: $(CLASS_DIR)/class_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/class_test.exe $(CLASS_DIR)/class_test.cpp $(wildcard $(CLASS_DIR)/lib/*.cpp)
