#ifndef SERVER_CONFIGURATION_H
#define SERVER_CONFIGURATION_H

int CreateListener(int port);
void AttemptConnection(std::map<int,std::vector<std::string>> info,
                  std::string active, std::string remote);
std::string ClientInformation(int client);
int CreateAccept(int server);

#endif
