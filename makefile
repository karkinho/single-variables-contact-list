all: 
	make comp
	./app
comp:
	gcc ./src/main.c -Wall -g -o app
	gcc ./src/test.c -Wall -g -o test
	gcc ./src/maintest.c -Wall -g -o apptest
compsan:
	gcc ./src/main.c -Wall -fsanitize=address -g -o app
	gcc ./src/test.c -Wall -fsanitize=address -g -o test
	gcc ./src/maintest.c -fsanitize=address -Wall -g -o apptest
tests:
	make comp
	./test | ./apptest
val:
	make comp
	./test | valgrind -s ./apptest