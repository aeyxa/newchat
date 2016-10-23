
client: client.o client_ncurses.o client_configuration.o client_communication.o
	g++ -o client client.o client_ncurses.o client_configuration.o client_communication.o ../common/* -pthread -lncurses -lssl -lcrypto -std=c++11

client.o: client.cpp
	g++ -c client.cpp -pthread -lncurses -lssl -lcrypto -std=c++11

client_ncurses.o: client_ncurses.cpp client_ncurses.h
	g++ -c client_ncurses.cpp -pthread -lncurses -lssl -lcrypto -std=c++11

client_configuration.o: client_configuration.cpp client_configuration.h
	g++ -c client_configuration.cpp -pthread -lncurses -lssl -lcrypto -std=c++11

client_communication.o: client_communication.cpp client_communication.h
	g++ -c client_communication.cpp -pthread -lncurses -lssl -lcrypto -std=c++11

clean:
	rm *.o client

key:
	openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout aeyxa.pem -out aeyxa.pem
