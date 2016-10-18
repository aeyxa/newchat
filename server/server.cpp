#include "../common/common.h"
#include "server.h"
#include "server_configuration.h"
#include "server_communication.h"

int main()
{
  server = CreateListener();

  for(;;)
  {
    client = CreateAccept(server);

    if(client > 0)
    {
      info[client];

      active = ClientInformation(client);
      remote = ClientInformation(client);

      info[client].push_back(active);
      info[client].push_back(remote);
    }

    sock = CheckMemory(info,active,remote);

    if(sock > 0)
    {
      int pid = fork();

      if(pid == 0)
      {
        close(server);
        ConfirmConnection(client,sock);
        ConnectionThreads(client,sock);
      }
      close(client);
    }

    info.erase(client); info.erase(sock);
  }
}
