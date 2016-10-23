#include "../common/common.h"

void UtilizeConnection(SSL *one, SSL *two)
{
  char buffer[256];

  while(strcmp(buffer,"quit") != 0)
  {
    char append_one[300]; char append_two[300];

    memset(buffer,0,sizeof(buffer));

    if(SSL_read(one,buffer,sizeof(buffer)))
    {
      strcpy(append_one,"1"); strcat(append_one,buffer);
      strcpy(append_two,"2"); strcat(append_two,buffer);

      SSL_write(one,append_one,sizeof(append_one));
      SSL_write(two,append_two,sizeof(append_two));
    }
    else break;
  }
  SSL_write(one,"2quit",5); SSL_write(two,"2quit",5);
}

void ConnectionThreads(int socket_one, int socket_two)
{
  SSL *ssl_one, *ssl_two;

  ssl_one = WrapSocketWithSSL(socket_one,"server");
  ssl_two = WrapSocketWithSSL(socket_two,"server");

  std::thread thread_one(UtilizeConnection,ssl_one,ssl_two);
  std::thread thread_two(UtilizeConnection,ssl_two,ssl_one);

  thread_one.join(); thread_two.join();
}
