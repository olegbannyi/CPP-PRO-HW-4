make: clean build run
run:
	./cpp-pro-xw-4.x
build: clean main.o math.o
	g++ -std=c++20 main.o math.o -o cpp-pro-xw-4.x
main.o: main.cpp
	g++ -std=c++20 -c main.cpp
math.o: math.cpp
	g++ -std=c++20 -c math.cpp
clean:
	rm -f *.o *.x