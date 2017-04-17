# aeyxachat

A linux command line chat software, that uses openssl to encrypt the communcation sockets for secure messaging.

### Though functional, this project has been deprecated in favor of other projects.

## No make file or installer has been created yet, however the program is currently functional.

If you wish to test the program out, you will need to download the entire project. You will need to change the port number, to an available open on your firewall with in the client_configuration.cpp file, on the CreateConnection() function and the "gethostbyname("71.6.134.109");" to the IP address you will be executing the server from. You will need to also change the port number on the server_configuration.cpp file on the CreateListener() function to an available port on your firewall.


## Additional packages will be required

You will need to have the necessary packages for openssl and ncurses installed, or you can wait until an installer is created and uploaded to this repository (coming soon).


## Compile Client

g++ -o client client.cpp client_communication.cpp client_configuration.cpp client_ncurses.cpp ../common/* -pthread -lncurses -lssl -lcrypto -std=c++11


## Compile Server

g++ -o server server.cpp server_communcation.cpp server_configuration.cpp ../common* -pthread -lncurses -lssl -lcrypto -std=c++11

You can use programs like tmux to have two client windows open and your server at the same time. Then execute both client programs and type opposite names for connection, such as "Your Name: Client1, Their Name: Client2" and "Your Name: Client2, Their Name: Client1" then you should be automatically brought into a chat session, assuming all packages were installed and have been compiled correctly, that your server IP address and port have been configured correctly with in the code and on your server.


## Future improvements

A make file will be created to allow for each installation and a configuration file to allow for customization of things such as font colors, server IP address and port, additionally a dedicated server will be accessible and a new installer just for the client side to use our server for free!
