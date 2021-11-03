#include <iostream>
#include <asio.hpp>
#include <cstdlib>

#include "Mode.h"

using asio::ip::tcp;

enum { max_length = 1024 };

int main(int argc, char* argv[]){
  /*try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
      return 1;
    }
    asio::io_context a;
    Mode mode(&a);
    asio::io_context* io_context = &a;

    tcp::socket* s = new tcp::socket(*io_context);
    tcp::resolver* resolver = new tcp::resolver(*io_context);
    asio::connect(*s, resolver->resolve(argv[1], argv[2]));

    std::cout << "Enter message: ";
    char request[max_length];
    std::cin.getline(request, max_length);
    size_t request_length = std::strlen(request);
    asio::write(*s, asio::buffer(request, request_length));

    char reply[max_length];
    size_t reply_length = asio::read(*s,
        asio::buffer(reply, request_length));
    std::cout << "Reply is: ";
    std::cout.write(reply, reply_length);
    std::cout << "\n";
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }*/
  try{
  Mode* M;
  asio::io_context con;

  if (argc <= 2){ // failure
    std::cout << "Failed initalizing\n";
    exit(1);
  }

  switch (*argv[1]){
    case 's':
      std::cout << "Server selected\n";
      M = new Server(con, std::atoi(argv[2]));
      break;
    case 'c':
    std::cout << "Client selected\n";
      M = new Client(con, argv[2], argv[3]);
      M->Handle();
      break;
  }

  std::cout << "Created object\n";
  con.run();
}
catch(std::exception& e){
  std::cout << "Exception: " << e.what() <<  '\n';
}

  return 0;
}
