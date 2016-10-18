#include "../common/common.h"

void UtilizeConnection(SSL *one, SSL *two)
{
  char buffer[256];

  for(;;)
  {
    memset(buffer,0,sizeof(buffer));

    if(SSL_read(one,buffer,sizeof(buffer)))
    {
      SSL_write(two,buffer,sizeof(buffer));
    }
    else break;
  }
}

void ConnectionThreads(int socket_one, int socket_two)
{
  SSL *ssl_one, *ssl_two;

  ssl_one = WrapSocketWithSSL(socket_one);
  ssl_two = WrapSocketWithSSL(socket_two);

  SSL_accept(ssl_one); SSL_accept(ssl_two);

  std::thread thread_one(UtilizeConnection,ssl_one,ssl_two);
  std::thread thread_two(UtilizeConnection,ssl_two,ssl_one);

  thread_one.join(); thread_two.join();
}
