UtilizeConnection(int one, int two)
{
  char buffer[256];

  for(;;)
  {
    read(one,buffer,sizeof(buffer));
    write(two,buffer,sizeof(buffer));
  }
}

ConnectionThreads(int socket_one, int socket_two)
{
  std::thread thread_one(UtilizeConnection,socket_one,socket_two);
  std::thread thread_two(UtilizeConnection,socket_two,socket_one);

  thread_one.join();
  thread_two.join();
}
