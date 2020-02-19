#
# PROGRAM:	assign4
# PROGRAMMER:	Branden Hidalgo
# LOGON ID:	z1663752
# DATE DUE:	03/08/18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11 -g

# Rule to link object code files to create executable file
assign4: assign4.o Vector3.o
	g++ $(CCFLAGS) -o assign4 assign4.o Vector3.o 

# Rules to compile source code files to object code
assign4.o: assign4.cpp Vector3.h
	g++ $(CCFLAGS) -c assign4.cpp

Vector3.o: Vector3.cpp Vector3.h
	g++ $(CCFLAGS) -c Vector3.cpp

# Pseudo-target to remove object code and executable files:
clean:
	-rm *.o assign4
