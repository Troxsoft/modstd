all:
	g++ -c src/MString.hpp src/MVector.hpp
	ar rvs modsts.a MString.o MVector.o