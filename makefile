bin/main: src/main.cpp bin/user.o bin/database.o
	g++ -g src/main.cpp bin/user.o bin/database.o -o bin/userTest

bin/user.o: include/user.hpp src/user.cpp
	g++ -c -g src/user.cpp -o bin/user.o

bin/database.o: include/database.hpp src/database.cpp
	g++ -c -g src/database.cpp -o bin/database.o
