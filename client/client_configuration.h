#ifndef CLIENT_CONFIGURATION_H
#define CLIENT_CONFIGURATION_H

void StageConnection(int sock);
void CheckConnection(int sock);
std::string ReadConnection(int sock);
int CreateConnection(struct hostent *server);

#endif
