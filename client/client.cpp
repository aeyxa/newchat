int main(int argc, char *argv[])
{
  sock = CreateConnection(server);

  CheckConnection(sock);
  StageConnection(sock);

  close(sock);
}
