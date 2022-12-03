CFLAGS =-g -Wall -Werror -pedantic
FILENAME = day3p1 day3p2

day2: day3p1.cpp day3p2.cpp
	g++ $(CFLAGS) day3p1.cpp -o day3p1
	g++ $(CFLAGS) day3p2.cpp -o day3p2

clean:
	rm -f $(FILENAME)

run1:
	./day3p1

run2:
	./day3p2

test1:
	./day3p1 < biginput.txt

test2:
	./day3p2 < biginput.txt