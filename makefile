bin/main: src/main.cpp bin/user.o bin/database.o
<<<<<<< HEAD
	g++ -g src/main.cpp bin/user.o bin/database.o -o bin/main

bin/userTest: src/test/userTest.cpp bin/user.o bin/database.o
	g++ -g src/test/userTest.cpp bin/user.o bin/database.o -o bin/userTest
=======
	g++ -g src/main.cpp bin/user.o bin/database.o -o bin/userTest
>>>>>>> feb47bd928b12282e30fd5cefce5b5d554161c8c

bin/user.o: include/user.hpp src/user.cpp
	g++ -c -g src/user.cpp -o bin/user.o

bin/database.o: include/database.hpp src/database.cpp
	g++ -c -g src/database.cpp -o bin/database.o

.PHONY:
clean:
	rm bin/*
