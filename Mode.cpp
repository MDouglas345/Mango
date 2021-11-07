#include "Mode.h"

void Server::Read(char* Buffer, size_t len){

}

void Server::Write(char* Buffer, size_t len){

}

void Server::Handle(){


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
}

void Server::Init(){
  //TODO Read all table data files and put into memory

  //TODO Whatever other data needs to intalized?
}

void Client::Read(char* Buffer, size_t len){

}

void Client::Write(char* Buffer, size_t len){

}

void Client::Handle(){
  std::cout << std::string(50, '\n'); // clear the screen

  std::cout << "------------------Welcome to Mango---------------------\n";
  std::cout << "------------------A Private Server---------------------\n";
  std ::cout << std::string(3,'\n');
  std::cout << "username: ";
  std::string user, pass;
  std::cin >> user;
  std::cout << "password: ";
  std::cin >> pass;


  MAuthenticate Auth;
  memcpy(Auth.User,user.c_str(), user.length()+1);
  memcpy(Auth.Password, pass.c_str(), pass.length()+1);

  std::cout << Auth.User << " " << Auth.Password << "\n";


  std::memcpy(WriteBuffer, &Auth, sizeof(Auth));

  asio::write(socket, asio::buffer(WriteBuffer, sizeof(Auth)));


}
