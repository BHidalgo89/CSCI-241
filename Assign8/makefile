#
# PROGRAM:    assign8
# PROGRAMMER: Branden Hidalgo
# LOGON ID:   z1663752
# DATE DUE:   
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o 
	g++ $(CCFLAGS) -o assign8 assign8.o 

# Rules to compile source code files to object code
assign8.o: assign8.cpp sorts.h mergesort.h quicksort.h
	g++ $(CCFLAGS) -c assign8.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8


