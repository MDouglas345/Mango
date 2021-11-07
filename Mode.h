#ifndef MODE_H
#define MODE_H

#include <asio.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "Session.h"
#include "ServerData.h"

class Mode{
protected:
  asio::io_context& io_context;
  asio::ip::tcp::socket socket;
public:
  Mode(asio::io_context& c) : io_context(c), socket(c){}
  virtual void Write(char* Message, size_t len) = 0;
  virtual void Read(char* Buffer, size_t len) = 0;
  virtual void Handle() = 0;
};

class Server : public Mode{
private:
  asio::ip::tcp::acceptor acceptor;
  std::vector<client_login_data> LoginTable;
public:
  Server(asio::io_context& c, short port) : Mode(c), acceptor(c, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)){std::cout << "Created Server\n"; Init();Handle();}
  void Write(char* Message, size_t len) override;
  void Read(char* Buffer, size_t len) override;
  void Handle() override;
  void Init();
};


class Client : public Mode{
private:
  asio::ip::tcp::resolver resolver;
  char WriteBuffer[1024];
public:
  Client(asio::io_context& c, char* addr, char* port) : Mode(c), resolver(c){ std::cout << "Created Client, connected to " << addr << " " << port << "\n";asio::connect(socket, resolver.resolve(addr, port)); }
  void Write(char* Message, size_t len) override;
  void Read(char* Buffer, size_t len) override;
  void Handle() override;
};
#endif
