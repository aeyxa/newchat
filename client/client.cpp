#include "../common/common.h"
#include "client_configuration.h"
#include "client_communication.h"

int main()
{
  int sock = CreateConnection();

  StageConnection(sock);
  CheckConnection(sock);
  SpeakConnection(sock);

  close(sock);
}
