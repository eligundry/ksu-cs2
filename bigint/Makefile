# bigint

###############################################################
# Variables
GCC  = g++
OPTS = -Wall -g

###############################################################
# The first rule is run of only make is typed
msg:
	@echo 'Targets are:'
	@echo '  tests:'
	@echo '  clean:'

###############################################################
# Build and run all tests and output demonstration
tests: test_default_ctor test_int_ctor test_c_str_ctor         \
	   test_add test_subscript                             \
	   test_times_10 test_times_single_digit test_multiply \
	   output input input2
	./test_default_ctor
	./test_int_ctor
	./test_c_str_ctor
	./test_add
	./test_subscript
	./test_times_10
	./test_times_single_digit
	./test_multiply
	./output
	./input
	./input2

#==============================================================
# bigint type
bigint.o: bigint.h bigint.cpp
	$(GCC) $(OPTS) -c bigint.cpp

#==============================================================
# Test default ctor
test_default_ctor: test_default_ctor.o bigint.o
	$(GCC) $(OPTS) -o test_default_ctor test_default_ctor.o bigint.o

test_default_ctor.o: bigint.h test_default_ctor.cpp
	$(GCC) $(OPTS) -c test_default_ctor.cpp

#==============================================================
# Test int ctor
test_int_ctor: test_int_ctor.o bigint.o
	$(GCC) $(OPTS) -o test_int_ctor test_int_ctor.o bigint.o

test_int_ctor.o: bigint.h test_int_ctor.cpp
	$(GCC) $(OPTS) -c test_int_ctor.cpp

#==============================================================
# Test C-string ctor
test_c_str_ctor: test_c_str_ctor.o bigint.o
	$(GCC) $(OPTS) -o test_c_str_ctor test_c_str_ctor.o bigint.o

test_c_str_ctor.o: bigint.h test_c_str_ctor.cpp
	$(GCC) $(OPTS) -c test_c_str_ctor.cpp

#==============================================================
# Test C-string ctor
test_add: test_add.o bigint.o
	$(GCC) $(OPTS) -o test_add test_add.o bigint.o

test_add.o: bigint.h test_add.cpp
	$(GCC) $(OPTS) -c test_add.cpp

#==============================================================
# Test C-string ctor
test_subscript: test_subscript.o bigint.o
	$(GCC) $(OPTS) -o test_subscript test_subscript.o bigint.o

test_subscript.o: bigint.h test_subscript.cpp
	$(GCC) $(OPTS) -c test_subscript.cpp

#==============================================================
# Test C-string ctor
test_times_10: test_times_10.o bigint.o
	$(GCC) $(OPTS) -o test_times_10 test_times_10.o bigint.o

test_times_10.o: bigint.h test_times_10.cpp
	$(GCC) $(OPTS) -c test_times_10.cpp

#==============================================================
# Test C-string ctor
test_times_single_digit: test_times_single_digit.o bigint.o
	$(GCC) $(OPTS) -o test_times_single_digit test_times_single_digit.o bigint.o

test_times_single_digit.o: bigint.h test_times_single_digit.cpp
	$(GCC) $(OPTS) -c test_times_single_digit.cpp

#==============================================================
# Test C-string ctor
test_multiply: test_multiply.o bigint.o
	$(GCC) $(OPTS) -o test_multiply test_multiply.o bigint.o

test_multiply.o: bigint.h test_multiply.cpp
	$(GCC) $(OPTS) -c test_multiply.cpp

#==============================================================
# Output demonstration
output: output.o bigint.o
	$(GCC) $(OPTS) -o output output.o bigint.o

output.o: bigint.h output.cpp
	$(GCC) $(OPTS) -c output.cpp

#==============================================================
# Input demonstration, addition
input: input.o bigint.o
	$(GCC) $(OPTS) -o input input.o bigint.o

input.o: bigint.h input.cpp
	$(GCC) $(OPTS) -c input.cpp

#==============================================================
# Input demonstration, multiplication
input2: input2.o bigint.o
	$(GCC) $(OPTS) -o input2 input2.o bigint.o

input2.o: bigint.h input2.cpp
	$(GCC) $(OPTS) -c input2.cpp

###############################################################
clean:
	rm -f *.o
	rm -f test_default_ctor test_int_ctor test_c_str_ctor 
	rm -f test_add test_subscript
	rm -f test_times_10 test_times_single_digit test_multiply
	rm -f output input input2

