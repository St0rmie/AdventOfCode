CFLAGS =-g -Wall -Werror -pedantic
CPP1 = day4p1.cpp
CPP2 = day4p2.cpp
FILENAME1 = day4p1
FILENAME2 = day4p2

$(FILENAME1): $(CPP1)
	g++ $(CFLAGS) $(CPP1) -o $(FILENAME1)

$(FILENAME2): $(CPP2) 
	g++ $(CFLAGS) $(CPP2) -o $(FILENAME2)

all: $(FILENAME1) $(FILENAME2)
	g++ $(CFLAGS) $(CPP1) -o $(FILENAME1)
	g++ $(CFLAGS) $(CPP2) -o $(FILENAME2)

clean:
	rm -f $(FILENAME1) $(FILENAME2)

run1:
	./$(FILENAME1)

run2:
	./$(FILENAME2)

test1:
	./$(FILENAME1) < biginput.txt

test2:
	./$(FILENAME2) < biginput.txt