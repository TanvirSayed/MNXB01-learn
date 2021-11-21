# the compiler 
CXX=g++

#C++ standard
CXXSTANDARD=-std=c++11
# check for warnings and errors
CXXWARNINGS= -Wall -Wextra -Werror
#directory to our header files and external library files
INCLUDES=-I include/ -I external/
#libraries for use, for the external CSV we need system threading library
LIBS=-lpthread
CXXFLAGS=$(CXXWARNIGS) $(INCLUDES) $(CXXSTANDARD)

#rule for creating the executable "testNuclei"
#
# Nuclei depends on the object files Nucleus.o compiled already

# command producing the testNucleus executable
testNuclei: testNuclei.o src/Nucleus.o src/parse_csv.o
	$(CXX) $(CXXFLAGS) testNuclei.o src/Nucleus.o src/parse_csv.o -o testNuclei $(LIBS)

#rule for the main executable file
testNuclei.o: testNuclei.cxx
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c testNuclei.cxx

#Rules for creating the src/Nucleus.o object file
src/Nucleus.o: src/Nucleus.cxx
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/Nucleus.cxx -o src/Nucleus.o

#Rules for creating the src/parse_csv.o object file 
src/parse_csv.o: src/parse_csv.cxx
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c src/parse_csv.cxx -o src/parse_csv.o

