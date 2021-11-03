#ifndef SESSION_H
#define SESSION_H

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

#include "Messages.h"

#define READBUFFSIZE 1024

class Server;

class Session : public std::enable_shared_from_this<Session>{
private:
  char ReadBuffer[READBUFFSIZE];
  const size_t ReadBufferSize = READBUFFSIZE;

public:
  asio::ip::tcp::socket socket;
  Server* Master;

  Session(asio::ip::tcp::socket s, Server* m) : socket(std::move(s)), Master(m){ }
  void HandleRead();
  void HandleWrite();
  void Start();

};
#endif
