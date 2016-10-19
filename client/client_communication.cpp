#include "../common/common.h"

void Reading(SSL *ssl)
{
  char buffer[256];

  for(;;)
  {
    memset(buffer,0,sizeof(buffer));

    if(SSL_read(ssl,buffer,sizeof(buffer)))
    {
      std::cout << buffer << std::endl;
    }
    else break;
  }
}

void Writing(SSL *ssl)
{
  char buffer[256];

  for(;;)
  {
    memset(buffer,0,sizeof(buffer));

    std::cout << "You: ";
    std::cin.getline(buffer,sizeof(buffer));
    SSL_write(ssl,buffer,sizeof(buffer));
  }
}

void SpeakConnection(int sock)
{
  SSL *ssl = WrapClientWithSSL(sock);

  std::thread thread_one(Writing,ssl);
  std::thread thread_two(Reading,ssl);

  thread_one.join(); thread_two.join();
}
