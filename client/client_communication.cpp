#include "../common/common.h"

void Reading(int sock)
{
  char buffer[256];

  for(;;)
  {
    memset(buffer,0,sizeof(buffer));

    if(read(sock,buffer,sizeof(buffer)))
    {
      std::cout << buffer << std::endl;
    }
    else break;
  }
}

void Writing(int sock)
{
  char buffer[256];

  for(;;)
  {
    memset(buffer,0,sizeof(buffer));
    std::cout << "You: ";
    std::cin.getline(buffer,sizeof(buffer));
    write(sock,buffer,sizeof(buffer));
  }
}

void SpeakConnection(int sock)
{
  std::thread thread_one(Reading,sock);
  std::thread thread_two(Writing,sock);

  thread_one.join();
  thread_two.join();
}
