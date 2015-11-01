FLAGS = -Wall -Werror -ansi -pedantic
OBJS = execute.o parse.o

all: rshell 
	g++ $(FLAGS) src/cho.cpp -o /bin/echo
	g++ $(FLAGS) src/ls.cpp -o /bin/ls
	g++ $(FLAGS) src/mkdir.cpp -o /bin/mkdir

rshell: execute.o parse.o
	g++ $(FLAGS) src/rshell.cpp -o /bin/rshell
 
execute.o:
	g++ $(FLAGS) -c src/execute.h

parse.o:
	g++ $(FLAGS) -c src/parse.h

clean:
	\rm *.o
