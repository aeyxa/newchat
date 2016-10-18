#include "../common/common.h"
#include "client.h"
#include "client_configuration.h"
#include "client_communication.h"

int main()
{
  sock = CreateConnection();

  StageConnection(sock);
  CheckConnection(sock);
  SpeakConnection(sock);

  close(sock);
}
