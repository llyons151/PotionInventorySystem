# Variables
GXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Link the object file into an executable called program2.out
program2.out: program2_driver.o inventory.o potion.o
	$(GXX) $(CXXFLAGS) -o program2.out program2_driver.o inventory.o potion.o

# Compile main driver file to an object file
program2_driver.o: src/program2_driver.cpp
	$(GXX) $(CXXFLAGS) -c src/program2_driver.cpp

# Compile inventory class file to an object file
inventory.o: src/inventory.cpp
	$(GXX) $(CXXFLAGS) -c src/inventory.cpp

# Compile potion class file to an object file
potion.o: src/potion.cpp
	$(GXX) $(CXXFLAGS) -c src/potion.cpp

# Run the compiled program2.out executable
run: program2.out
	./program2.out

# Delete all of the object files
clean:
	rm -f *.o program2.out
