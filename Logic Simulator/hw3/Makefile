CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

llrec-test: llrec.o 
	$(CXX) $(CXXFLAGS) -o $@ llrec-test.cpp llrec.o llrec.h


llrec.o: llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp
#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 