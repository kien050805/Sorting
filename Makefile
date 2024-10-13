all: mytests

mytests: mytests.o sorting
	g++ -o mytests mytests.o sorting
	./mytests

mytests.o: mytests.cpp sorting.hpp
	g++ -c mytests.cpp

sorting: sorting.cpp sorting.hpp
	g++ -c sorting.cpp -o sorting
