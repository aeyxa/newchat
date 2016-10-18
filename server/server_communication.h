#ifndef SERVER_COMMUNICATION_H
#define SERVER_COMMUNICATION_H

void UtilizeConnection(SSL *one, SSL *two);
void ConnectionThreads(int socket_one, int socket_two);

#endif
