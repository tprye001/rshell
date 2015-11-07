FLAGS = -Wall -Werror -ansi -pedantic
OBJS = execute.o parse.o

all: rshell dir 
	g++ $(FLAGS) src/echo.cpp -o bin/echo
	g++ $(FLAGS) src/ls.cpp -o bin/ls
	g++ $(FLAGS) src/mkdir.cpp -o bin/mkdir

rshell: dir
	g++ -g $(FLAGS) src/rshell.cpp -o bin/rshell
 
dir:
	mkdir bin
#execute.o:
	#g++ $(FLAGS) -c src/execute.h

#parse.o:
	#g++ $(FLAGS) -c src/parse.h

#clean:
	#\rm *.o
