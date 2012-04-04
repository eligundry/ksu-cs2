#============================================================================
#  stack class makefile
#===========================================================================

CPP          = g++
CPP_FLAGS    = -g -Wall -W -Wunused -Wuninitialized -Wshadow 
INCLUDE_OPT  = -iquote . -iquote ../string
TEST_1 = test_stack
TEST_2 = 
TEST_3 = 

#-------------------------------------------------------------------------------
STRING_DIR = ../string/

#===========================================================================
msg:
	@echo 'Targets for compiling test programs:'
	@echo '   tests'
	@echo '   clean'

#===========================================================================
# Compile string.o
string.o:	${STRING_DIR}string.h  ${STRING_DIR}string.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c ${STRING_DIR}string.cpp

#===========================================================================
# Compile test programs
#----------------------------------------------------------------------------
test_%: string.o test_%.o
	${CPP} ${CPP_FLAGS} string.o test_$*.o -o test_$*

test_%.o: ${STRING_DIR}string.h stack.h test_%.cpp
	${CPP} ${CPP_FLAGS} ${INCLUDE_OPT} -c test_$*.cpp

#===========================================================================
# Run test programs

tests: ${TEST_1} ${TEST_2} ${TEST_3} 
	./test_stack

#===========================================================================
# Run memory tests

memtests: ${TEST_1} ${TEST_2} ${TEST_3} 
	valgrind ./test_stack

#===========================================================================
.PRECIOUS: test_%.o string.o

#============================================================================

clean:
	rm -f *.o a.out
	rm -f test_stack

