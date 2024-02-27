main: clean dataTypes.o functions.o app.o
	g++ -o main main.cpp dataTypes.o functions.o app.o
app:
	g++ -c app.cpp
functions:
	g++ -c functions.cpp
dataTypes:
	g++ -c dataTypes.cpp
clean:
	del *.o *.exe