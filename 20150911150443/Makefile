
##
#
# date: Sex Set 11 15:19:54 BRT 2015
# author: Joao Gustavo Cabral de Marins
# e-mail: jgcmarins@gmail.com
#
##

# compiler name
CC=g++

# flags
F=-Wall -std=c++11

# binary file
BIN=./build/graph_coloring

# main
MAIN=src/main/main.cc

# headers
H=./src/headers

# library
LIB=src/vertex/Vertex.cc src/graph/Graph.cc src/state/State.cc src/util/Tokenizer.cc src/core/Backtracking.cc

all: clean compile
clean:
	rm -rf build
	mkdir build
compile:
	$(CC) $(F) -o $(BIN) -I$(H) $(MAIN) $(LIB)
run:
	$(BIN)
valgrind:
	valgrind $(BIN)
runin1:
	$(BIN) < in/1
valgrindin1:
	valgrind $(BIN) < in/1
runbrasil:
	$(BIN) < in/brasil.in
valgrindbrasil:
	valgrind $(BIN) < in/brasil.in
runusa:
	$(BIN) < in/usa.in
valgrindusa:
	valgrind $(BIN) < in/usa.in
