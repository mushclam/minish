OBJS = minish.o shFunction.o

minish : ${OBJS}
	g++ -w -o minish ${OBJS}

minish.o : minish.cpp pch.h
	g++ -c minish.cpp

shFunction.o : shFunction.cpp shFunction.h
	g++ -c shFunction.cpp

clean:
	rm -r minish ${OBJS}
