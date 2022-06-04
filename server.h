#include <iostream>
#include <string>
#include <map>
#include <cerrno>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <boost/asio/thread_pool.hpp>
#include <boost/asio/post.hpp>

class Server
{
private:

    // method  For  Handling;
    int port;
public:
    struct Handler;
    Server(int port);
    Server();

public:
    void produce(int client_socket_fd);
  //  void addHandler();

};