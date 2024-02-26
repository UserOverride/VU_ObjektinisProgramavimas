main: functions.o dataTypes.o app.o
	g++ -o main main.cpp functions.o dataTypes.o app.o
app:
	g++ -c app.cpp
functions:
	g++ -c functions.cpp
dataTypes:
	g++ -c dataTypes.cpp
clean:
	del *.o *.exe