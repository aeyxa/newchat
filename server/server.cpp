#include "../common/common.h"
#include "server.h"
#include "server_configuration.h"

int main()
{
  server = CreateListener();

  for(;;)
  {
    client = CreateAccept(server);

    info[client];

    active = ClientInformation(client);
    remote = ClientInformation(client);

    info[client].push_back(active);
    info[client].push_back(remote);

    AttemptConnection(info,server,active,remote);

    info.erase(socket_one);
    info.erase(socket_two);
  }
}
