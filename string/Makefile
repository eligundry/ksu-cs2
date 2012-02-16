#==============================================================
# string

CPP     = g++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow 

EXE1 = test_default_ctor test_c_str_ctor test_subscript test_length test_less_than test_greater_than
EXE2 = 

#==============================================================
msg:
	@echo 'Targets are:'
	@echo '  string'
	@echo '  leaktest'
	@echo '  test_XXX  (where test_XXX is a test program)'
	@echo '  clean'

#==============================================================
# Run all tests
string: $(EXE1) $(EXE2)
	./test_default_ctor
	./test_c_str_ctor
	./test_subscript
	./test_length
	./test_less_than
	./test_greater_than

#==============================================================
# string type
string.o: string.h string.cpp
	$(CPP) -c $(OPTIONS) string.cpp

#===========================================================================
# Compile test programs
#----------------------------------------------------------------------------
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.h test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp

#===========================================================================
leaktest: $(EXE1) $(EXE2)
	valgrind ./test_default_ctor
	valgrind ./test_c_str_ctor

#===========================================================================
.PRECIOUS: test_%.o string.o

#==============================================================
# clean should remove all .o files and all executables
clean:
	rm -f *.o
	rm -f test_default_ctor test_c_str_ctor
	rm -f test_length test_subscript
	rm -f test_less_than test_greater_than

