all: 
	make comp
	./app
comp:
	gcc ./src/main.c -Wall -g -o app
	gcc ./src/tests.c -Wall -g -o tests
	gcc ./src/mainsupressed.c -Wall -g -o appsupressed
test:
	make comp
	./tests | ./appsupressed
val:
	make comp
	valgrind -s ./tests | ./appsupressed