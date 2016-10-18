#ifndef SERVER_CONFIGURATION_H
#define SERVER_CONFIGURATION_H

int CheckMemory(std::map<int,std::vector<std::string>> info,
                  std::string active, std::string remote);
void ConfirmConnection(int socket_one, int socket_two);
std::string ClientInformation(int client);
int CreateAccept(int server);
int CreateListener();

#endif
