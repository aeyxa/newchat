#ifndef SERVER_CONFIGURATION_H
#define SERVER_CONFIGURATION_H

int CheckMemory(MAP info, int client, std::string active, std::string remote);
MAP PlaceMemory(MAP info, int client, std::string active, std::string remote);
MAP CleanMemory(MAP info, int client, int sock);

MAP ConnectionLogic(MAP info, int sock, int client, int server);
void ConfirmConnection(int socket_one, int socket_two);

std::string ClientInformation(int client);
int CreateAccept(int server);
int CreateListener();

#endif
