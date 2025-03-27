CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17 -O3
VECTOR_LIB_DIR = konteineriai/vector
DEQUE_LIB_DIR = konteineriai/deque
LIST_LIB_DIR = konteineriai/list

all: build_d build_l build_v test_d test_l test_v

test: test_d test_l test_v

build: build_d build_l build_v

clean:
	del build\

build_d: $(DEQUE_LIB_DIR)/OOP1.cpp $(wildcard $(DEQUE_LIB_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_D.exe $(DEQUE_LIB_DIR)/OOP1.cpp $(wildcard $(DEQUE_LIB_DIR)/bibliotekos/*.cpp)

test_d: $(DEQUE_LIB_DIR)/testavimas.cpp $(wildcard $(DEQUE_LIB_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/testavimas_D.exe $(DEQUE_LIB_DIR)/testavimas.cpp $(wildcard $(DEQUE_LIB_DIR)/bibliotekos/*.cpp)

build_l: $(LIST_LIB_DIR)/OOP1.cpp $(wildcard $(LIST_LIB_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_L.exe $(LIST_LIB_DIR)/OOP1.cpp $(wildcard $(LIST_LIB_DIR)/bibliotekos/*.cpp)

test_l: $(LIST_LIB_DIR)/testavimas.cpp $(wildcard $(LIST_LIB_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/testavimas_L.exe $(LIST_LIB_DIR)/testavimas.cpp $(wildcard $(LIST_LIB_DIR)/bibliotekos/*.cpp)

build_v: $(VECTOR_LIB_DIR)/OOP1.cpp $(wildcard $(VECTOR_LIB_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_V.exe $(VECTOR_LIB_DIR)/OOP1.cpp $(wildcard $(VECTOR_LIB_DIR)/bibliotekos/*.cpp)

test_v: $(VECTOR_LIB_DIR)/testavimas.cpp $(wildcard $(VECTOR_LIB_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/testavimas_V.exe $(VECTOR_LIB_DIR)/testavimas.cpp $(wildcard $(VECTOR_LIB_DIR)/bibliotekos/*.cpp)