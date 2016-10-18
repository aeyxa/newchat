#include "../common/common.h"
#include "server_communication.h"

void ConfirmConnection(int socket_one, int socket_two)
{
  char buffer_one[256]; char buffer_two[256];
  std::string validation; bool one, two;

  write(socket_one,"Connected!",13);
  write(socket_two,"Connected!",13);

  if(read(socket_one,buffer_one,sizeof(buffer_one)))
  {
    validation = buffer_one;

    if(validation == "Online")
    {
      one = true;
    }
  }
  if(read(socket_two,buffer_two,sizeof(buffer_two)))
  {
    validation = buffer_two;

    if(validation == "Online")
    {
      two = true;
    }
  }
  if(one && two)
  {
    write(socket_one,"Confirmed!",13);
    write(socket_two,"Confirmed!",13);
  }
  else
  {
    if(one){ write(socket_one,"fail",4); }
    if(two){ write(socket_two,"fail",4); }

    exit(1);
  }
}

int CheckMemory(std::map<int,std::vector<std::string>> info,
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
    return socket_one;
  }
  else return -1;
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

  if(client)
  {
    return client;
  }
  else return -1;
}

int CreateListener()
{
  int sock, port = 9999; struct sockaddr_in address;

  sock = socket(AF_INET,SOCK_STREAM,0);
  memset(&address,0,sizeof(address));

  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = INADDR_ANY;

  if(bind(sock,(struct sockaddr*)&address,sizeof(address)))
  {
    listen(sock,10); return sock;
  }
  else std::cout << "Failed to bind" << std::endl; exit(1);
}
