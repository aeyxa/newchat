int CreateConnection(struct hostent *server)
{
  int sock, port = 9999; struct sockaddr_in address;

  memset(&address,0,sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  memcpy((char *)&address.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

  sock = socket(AF_INET,SOCK_STREAM,0);
  check(errno);

  connect(sock,(struct sockaddr*)&address,sizeof(address));
  check(errno);

  return sock;
}
