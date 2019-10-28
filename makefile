all: servidor cliente

servidor: servidor.o
	g++ -lzmq -std=c++11 -o servidor servidor.o

cliente: cliente.o
	g++ -lzmq -std=c++11 -o cliente cliente.o

servidor.o: servidor.cpp
	g++ -lzmq -std=c++11 -o servidor.o -c servidor.cpp

cliente.o: cliente.cpp
	g++ -lzmq -std=c++11 -o cliente.o -c cliente.cpp


clean:
	rm *.o
