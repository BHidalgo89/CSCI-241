#
# PROGRAM:	assign6
# PROGRAMMER:	Branden Hidalgo
# LOGON ID:	Z1663752
# DATE DUE:	
#

# Compiler Variables
CCFLAGS = -Wall -std=c++11 -g

# Rule to link object code files to create executable file
assign6: assign6.o
	g++ $(CCFLAGS) -o assign6 assign6.o

# Rules to compile source code files to object code
assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

# Pseudo-target to remove object code and executable files:
clean:
	-rm *.o assign6
