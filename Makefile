# Victor Forbes - 9293394

all:
	gcc src/*.c -I include/ -o main -g -Wall
run:
	./main
debug:
	valgrind -v --leak-check=full --track-origins=yes --show-leak-kinds=all ./main