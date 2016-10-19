#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <fstream>
#include <malloc.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <resolv.h>
#include <vector>
#include <netdb.h>
#include <map>
#include <set>
#include <thread>
#include <ncurses.h>

#define MAP std::map<int,std::vector<std::string>>

void LoadCertificates(SSL_CTX* ctx, char* CertFile, char* KeyFile);
SSL* WrapClientWithSSL(int sock);
SSL* WrapServerWithSSL(int sock);
SSL_CTX* InitServerCTX(void);

#endif
