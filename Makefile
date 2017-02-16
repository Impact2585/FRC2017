Target := FRCUserProgram

Sources := $(shell find src -name '*.cpp')

Binfolder = Debug

CXX = arm-frc-linux-gnueabi-g++

CPPVERSION = -std=c++1y

CPPFlags = -O0 -Og -g3 -Wall -c -fmessage-length=0

INCLUDE = -I../../wpilib/cpp/current/include -I./src/ -I../../wpilib/user/cpp/include -I./wpilib-cpp/include 

LIBS = -L../../wpilib/cpp/current/lib -L../../wpilib/user/cpp/lib -L./wpilib-cpp/lib -Wl,-rpath,/opt/GenICam_v3_0_NI/bin/Linux32_ARM,-rpath,/usr/local/frc/lib -lwpi 

DESTPATH = $(Binfolder)/$(Target)
	
all: compile removeobjs

deploy: compile removeobjs
	ant

compile: makebin $(patsubst %.cpp, %.o, $(Sources))
	$(CXX) $(CPPVERSION) $(LIBS) -o $(DESTPATH) $(shell find src -name '*.o')
	
%.o: %.cpp
	$(CXX) $(CPPVERSION) $(INCLUDE) $(CPPFlags) -o $@ $<

.PHONY: all deploy compile clean removeobjs 

makebin:
	[[ -d Debug ]] || mkdir Debug

removeobjs:
	$(shell find src -name '*.o' -exec rm {} \;)

clean: 
	@$(RM) $(DESTPATH)

