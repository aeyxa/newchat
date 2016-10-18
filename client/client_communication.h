#ifndef CLIENT_COMMUNICATION_H
#define CLIENT_COMMUNICATION_H

void Reading(SSL *ssl);
void Writing(SSL *ssl);
void SpeakConnection(int sock);

#endif
