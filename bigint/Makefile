# bigint

###############################################################
# The first rule is run of only make is typed
msg:
	@echo 'Targets are:'
	@echo '  tests:'
	@echo '  clean:'

###############################################################
# Build and run all tests and output demonstration
tests: test_default_ctor test_int_ctor test_c_str_ctor \
	   test_add test_subscript                     \
	   output input
	./test_default_ctor
	./test_int_ctor
	./test_c_str_ctor
	./test_add
	./test_subscript
	./output
	./input

#==============================================================
# bigint type
bigint.o: bigint.h bigint.cpp
	g++ -Wall -c bigint.cpp

#==============================================================
# Test default ctor
test_default_ctor: test_default_ctor.o bigint.o
	g++ -Wall -o test_default_ctor test_default_ctor.o bigint.o

test_default_ctor.o: bigint.h test_default_ctor.cpp
	g++ -Wall -c test_default_ctor.cpp

#==============================================================
# Test int ctor
test_int_ctor: test_int_ctor.o bigint.o
	g++ -Wall -o test_int_ctor test_int_ctor.o bigint.o

test_int_ctor.o: bigint.h test_int_ctor.cpp
	g++ -Wall -c test_int_ctor.cpp

#==============================================================
# Test C-string ctor
test_c_str_ctor: test_c_str_ctor.o bigint.o
	g++ -Wall -o test_c_str_ctor test_c_str_ctor.o bigint.o

test_c_str_ctor.o: bigint.h test_c_str_ctor.cpp
	g++ -Wall -c test_c_str_ctor.cpp

#==============================================================
# Test C-string ctor
test_add: test_add.o bigint.o
	g++ -Wall -o test_add test_add.o bigint.o

test_add.o: bigint.h test_add.cpp
	g++ -Wall -c test_add.cpp

#==============================================================
# Test C-string ctor
test_subscript: test_subscript.o bigint.o
	g++ -Wall -o test_subscript test_subscript.o bigint.o

test_subscript.o: bigint.h test_subscript.cpp
	g++ -Wall -c test_subscript.cpp

#==============================================================
# Output demonstration
output: output.o bigint.o
	g++ -Wall -o output output.o bigint.o

output.o: bigint.h output.cpp
	g++ -Wall -c output.cpp

#==============================================================
# Input demonstration
input: input.o bigint.o
	g++ -Wall -o input input.o bigint.o

input.o: bigint.h input.cpp
	g++ -Wall -c input.cpp

###############################################################
clean:
	rm -f *.o
	rm -f test_default_ctor test_int_ctor test_c_str_ctor 
	rm -f test_add test_subscript
	rm -f output input

