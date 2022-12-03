CFLAGS =-g -Wall -Werror -pedantic
FILENAME = day2p1 day2p2

day2: day2p1.cpp day2p2.cpp
	g++ $(CFLAGS) day2p1.cpp -o day2p1
	g++ $(CFLAGS) day2p2.cpp -o day2p2

clean:
	rm -f $(FILENAME)

run1:
	./day2p1

run2:
	./day2p2

test1:
	./day2p1 < biginput.txt

test2:
	./day2p2 < biginput.txt