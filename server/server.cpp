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

    active = ClientInformation(client);
    remote = ClientInformation(client);

    info = PlaceMemory(info,client,active,remote);
    sock = CheckMemory(info,client,active,remote);

    info = ConnectionLogic(info,sock,client,server);
  }
}
