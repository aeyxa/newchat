
server: server.o server_configuration.o server_communication.o
	g++ -o server server.o server_configuration.o server_communication.o ../common/* -pthread -lncurses -lssl -lcrypto -std=c++11

server.o: server.cpp
	g++ -c server.cpp -pthread -lncurses -lssl -lcrypto -std=c++11

server_configuration.o: server_configuration.cpp
	g++ -c server_configuration.cpp -pthread -lncurses -lssl -lcrypto -std=c++11

server_communication.o: server_communication.cpp
	g++ -c server_communication.cpp -pthread -lncurses -lssl -lcrypto -std=c++11

clean:
	rm *.o server

key:
	openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout aeyxa.pem -out aeyxa.pem
