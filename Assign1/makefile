#
#	PROGRAM:	assign1
#	PROGRAMMER:	Branden Hidalgo
#	LOGON ID:	z1663752
#	DATE DUE:	02/01
#

#	Compiler variables
CCFLAGS = -Wall -std=c++11

#	Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

#	Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1

