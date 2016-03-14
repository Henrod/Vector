CXX		= g++
CXXFLAGS 	= -std=c++11 -Wall -Wextra

#CPP_FILES = $(wildcard src/*.cpp)
CPP_FILES = src/main.cpp
OBJ_FILES = obj/main 

HPP_PATH  = hdr
CPP_PATH  = src
INC_PATH  = -I$(HPP_PATH) -I$(CPP_PATH)

all:
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) $(INC_PATH) $(CPP_FILES) -o $(OBJ_FILES)

clean:
	rm -rf obj/*
