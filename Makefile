CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17 -O3
VECTOR_DIR = konteineriai/vector
DEQUE_DIR = konteineriai/deque
LIST_DIR = konteineriai/list
CLASS_DIR = class

all: test build

test: test_d test_l test_v test_c

build: build_d build_l build_v build_c

clean:
	del build\

build_d: $(DEQUE_DIR)/OOP1.cpp $(wildcard $(DEQUE_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_D.exe $(DEQUE_DIR)/OOP1.cpp $(wildcard $(DEQUE_DIR)/bibliotekos/*.cpp)

test_d: $(DEQUE_DIR)/testavimas.cpp $(wildcard $(DEQUE_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/testavimas_D.exe $(DEQUE_DIR)/testavimas.cpp $(wildcard $(DEQUE_DIR)/bibliotekos/*.cpp)

build_l: $(LIST_DIR)/OOP1.cpp $(wildcard $(LIST_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_L.exe $(LIST_DIR)/OOP1.cpp $(wildcard $(LIST_DIR)/bibliotekos/*.cpp)

test_l: $(LIST_DIR)/testavimas.cpp $(wildcard $(LIST_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/testavimas_L.exe $(LIST_DIR)/testavimas.cpp $(wildcard $(LIST_DIR)/bibliotekos/*.cpp)

build_v: $(VECTOR_DIR)/OOP1.cpp $(wildcard $(VECTOR_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_V.exe $(VECTOR_DIR)/OOP1.cpp $(wildcard $(VECTOR_DIR)/bibliotekos/*.cpp)

test_v: $(VECTOR_DIR)/testavimas.cpp $(wildcard $(VECTOR_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/testavimas_V.exe $(VECTOR_DIR)/testavimas.cpp $(wildcard $(VECTOR_DIR)/bibliotekos/*.cpp)

build_c: $(CLASS_DIR)/OOP1.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_C.exe $(CLASS_DIR)/OOP1.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)

test_c: $(CLASS_DIR)/testavimas.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/testavimas_C.exe $(CLASS_DIR)/testavimas.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)