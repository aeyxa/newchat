#ifndef SERVER_H
#define SERVER_H

#define MAP std::map<int,std::vector<std::string>>

int server, client, sock;
std::string active, remote;
MAP info;

#endif
