int main()
{
  sock = CreateConnection();

  StageConnection(sock);
  CheckConnection(sock);
  SpeakConnection(sock);

  close(sock);
}
