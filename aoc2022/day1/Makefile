CFLAGS =-Wall -Werror -pedantic
FILE = day1.cpp
FILENAME = day1

day1: day1.cpp
	g++ $(CFLAGS) $(FILE) -o $(FILENAME)

clean:
	rm -f $(FILENAME)

run:
	./$(FILENAME)

run1:
	./$(FILENAME) < biginput.txt

run2:
	./$(FILENAME) < biggerinput.txt