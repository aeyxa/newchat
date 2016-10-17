#include "../common/common.h"

void AttemptConnection(std::map<int,std::vector<std::string>> info,
                  std::string active, std::string remote)
{
  int socket_one, socket_two;

  for(auto x = info.begin(); x != info.end(); ++x)
  {
    if(x->second[0] == remote && x->second[1] == active)
    {
      socket_one = x->first;
    }
    if(x->second[0] == active && x->second[1] == remote)
    {
      socket_two = x->first;
    }
  }

  if(socket_one && socket_two)
  {
    int pid = fork(); check(errno);

    if(pid == 0)
    {
      close(socket_two);

      speak(socket_one,socket_two);
    }
    close(socket_two);
  }
}

std::string ClientInformation(int client)
{
  char buffer[256]; std::string name;

  memset(buffer,0,sizeof(buffer));
  read(client,buffer,sizeof(buffer));

  name = buffer;

  return name;
}

int CreateAccept(int server)
{
  int client; struct sockaddr_in address;
  socklen_t length = sizeof(address);

  client = accept(server,(struct sockaddr*)&address,&length);

  return client;
}

int CreateListener()
{
  int sock, port = 9999; struct sockaddr_in address;

  sock = socket(AF_INET,SOCK_STREAM,0);
  memset(&address,sizeof(address));

  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = INADDR_ANY;

  bind(sock,(struct sockaddr*)&address,sizeof(address));

  check(errno); listen(sock,10);

  return sock;
}
