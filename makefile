main: clean dataTypes.o special.o functions.o app.o
	g++ -o main main.cpp dataTypes.o special.o functions.o app.o
app:
	g++ -c app.cpp
functions:
	g++ -c functions.cpp
dataTypes:
	g++ -c dataTypes.cpp
special:
	g++ -c special.cpp
clean:
	del *.o *.exe resBad*.txt resGood*.txt