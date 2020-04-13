OBJ = main.o CSVEditor.o
MAIN = main

$(MAIN): $(OBJ)
	g++-8.2.0 -std=c++17 -o $(MAIN) $(OBJ)

main.o: main.cpp HashTable.hpp
	g++-8.2.0 -std=c++17 -c main.cpp

CSVEditor.o: CSVEditor.cpp CSVEditor.hpp
	g++-8.2.0 -std=c++17 -c CSVEditor.cpp
	
clean: 
	rm -f $(OBJ) $(MAIN)
