CXX		= g++
CXXFLAGS 	= -std=c++11 -Wall -Wextra

CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = obj/main 

HPP_PATH  = hdr

all:
	@mkdir -p obj
	$(CXX) $(CXXFLAGS) -I$(HPP_PATH) $(CPP_FILES) -o $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)
