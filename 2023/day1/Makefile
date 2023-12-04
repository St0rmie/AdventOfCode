CC = g++
CXX = g++
LD = g++

DAY := day1

TARGETS = src/client/player src/server/server
TARGET_EXECS = $(DAY)p1 $(DAY)p2

DAYP1_SOURCES := $(DAY)p1.cpp
DAYP2_SOURCES := $(DAY)p2.cpp

DAYP1_OUT := $(DAY)p1.out
DAYP2_OUT := $(DAY)p1.out

CXXFLAGS = -std=c++17
LDFLAGS = -std=c++17

# Run `make OPTIM=no` to disable -O3
ifeq ($(strip $(OPTIM)), no)
	CXXFLAGS += -O0
else
	CXXFLAGS += -O3
endif

CXXFLAGS += -fdiagnostics-color=always

.PHONY: p1 p2 clean

all: $(TARGET_EXECS)

p1: 
	g++ $(CXXFLAGS) -o $(DAY)p1 $(DAY)p1.cpp 

p2: 
	g++ -o $(DAY)p2 $(DAY)p2.cpp

clean:
	rm -f $(TARGET_EXECS) project.zip

testp1: p1
	./$(DAY)p1 < inputp1.txt

testp2: p2
	./$(DAY)p2 < inputp2.txt

test: p1 p2
	./$(DAY)p1 < inputp1.txt
	./$(DAY)p2 < inputp2.txt
