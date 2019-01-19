CXXFLAGS = -Wall -g

BIN_NAME = ppmReader
SRC_DIR = ./src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES=  $(SRC_FILES:.cpp=.o) 

$(BIN_NAME): $(OBJ_FILES)
	$(LINK.cpp) -o $@ $(OBJ_FILES)

%: %.o
	$(LINK.cpp) -o $@ $^

depend:
	makedepend $(SRC_FILES)

clean:
	rm -f ./*/*.o

rdata:
	rm -f ./*.ppm

mrproper: clean rdata
	rm -f $(BIN_NAME)

remake: mrproper $(BIN_NAME)