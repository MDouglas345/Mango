#include "Mode.h"

void Server::Read(char* Buffer, size_t len){

}

void Server::Write(char* Buffer, size_t len){

}

void Server::Handle(){
  std::cout << "Handling..\n";

  acceptor.async_accept(socket,
      [this](std::error_code ec)
      {
        if (!ec)
        {
          std::cout << "Creating thread\n";
          std::make_shared<Session>(std::move(socket), this)->Start();
        }

        Handle();
      });
      
  std::cout << "Finished Handling\n";
}


void Client::Read(char* Buffer, size_t len){

}

void Client::Write(char* Buffer, size_t len){

}

void Client::Handle(){
  char c;
  int cc;
  std::cout << "enter 0 or 1\n";
  std::cin >> c;

  cc = std::atoi(&c);

  MInterface S;
  S.type = cc;

  std::memcpy(WriteBuffer, &S, sizeof(S));

  asio::write(socket, asio::buffer(WriteBuffer, sizeof(S)));


}
