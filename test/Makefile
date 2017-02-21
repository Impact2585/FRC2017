
TARGET := Test

Sources := $(shell find ../ ! -name "TimedDriveTask*" ! -name "Xbox*" ! -name "*Executor*" ! -name "Environment*" ! -name "Robot.cpp" -name "*.cpp")

CXX = g++

CPPVERSION = -std=c++1y

CPPFlags = -O0 -Og -g3 -Wall -c -fmessage-length=0 -DTESTING

INCLUDE = -I/usr/local/include

LIBS = -L/usr/local/lib -lcpptest

all: compile removeobjs

compile: $(patsubst %.cpp, %.o, $(Sources))
	$(CXX) $(CPPVERSION) $(LIBS) -o $(TARGET) $(shell find ../ -name '*.o')

%.o: %.cpp
	$(CXX) $(CPPVERSION) $(INCLUDE) $(CPPFlags) -o $@ $<

.PHONY: compile removeobjs

removeobjs:
	$(shell find ../ -name '*.o' -exec rm {} \;)

clean: $(TARGET)
	rm $(TARGET)
