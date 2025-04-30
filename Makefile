CXX = g++
CXXFLAGS = -fdiagnostics-color=always -g -std=c++17 -Os
CLASS_DIR = src

all: test_time test_class build

clean:
	del build\

build: $(CLASS_DIR)/OOP1.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/OOP1_C.exe $(CLASS_DIR)/OOP1.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)

test_time: $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/time_test_C.exe $(CLASS_DIR)/time_test.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)

test_class: $(CLASS_DIR)/class_test.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)
	$(CXX) $(CXXFLAGS) -o build/class_test_C.exe $(CLASS_DIR)/class_test.cpp $(wildcard $(CLASS_DIR)/bibliotekos/*.cpp)
