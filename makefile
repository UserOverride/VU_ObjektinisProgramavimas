main: functions.o dataTypes.o
	g++ -o vector vector.cpp functions.o dataTypes.o
functions:
	g++ -c functions.cpp
dataTypes:
	g++ -c dataTypes.cpp
clean:
	del *.o *.exe